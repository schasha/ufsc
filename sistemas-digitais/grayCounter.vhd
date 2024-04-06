library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity grayCounter is
	generic(	width: positive := 16;
				generateLoad: boolean := true;
				generateEnb: boolean := true;
				generateInc: boolean := true;
				resetValue: integer := 0 );
	port(	-- control
			clock, reset, load: in std_logic;
			enb, inc: in std_logic;
			-- data
			input: in std_logic_vector(width-1 downto 0);
			output: out std_logic_vector(width-1 downto 0)	);
end entity;


architecture behav0 of grayCounter is
    subtype state is signed(width-1 downto 0);
    signal nextState, currentState: state;
    signal tempNextState, tempNextState2: state;
    signal binInput: signed(width-1 downto 0);
begin
	-- next-state logic
	genLoad:
    if generateLoad generate
        tempNextState2 <= binInput when load = '1' else
                          tempNextState;
    end generate;
    
    genLoadNotEnb:
    if generateLoad and not generateEnb generate
        tempNextState <= binInput when load = '1' else
                         nextState;
    end generate;
   
    genEnbLoad:
    if generateLoad and generateEnb generate
        nextState <= tempNextState2 when enb = '1' else
                     currentState;
    end generate;
    
    genEnb:
    if generateEnb and not generateLoad generate
        nextState <= tempNextState when enb = '1' else
                     currentState;
    end generate;
    
    genNotEnb:
    if not generateEnb generate
        nextState <= tempNextState;
    end generate;
    
    genInc:
    if generateInc generate
        tempNextState <= currentState + 1 when inc = '1' else
                         currentState - 1;
    end generate;
    
    genNotInc:
    if not generateInc generate
        tempNextState <= currentState + 1;
    end generate;
	
	-- memory register
	process(clock, reset) is
	begin
		if reset='1' then
			currentState <= (to_signed(resetValue, currentState'length));
		elsif rising_edge(clock) then
			currentState <= nextState;
		end if;
	end process;
		
	-- output-logic
	-- decoder
	binInput(width-1) <= input(width-1);
    genDecoder:
    for i in 0 to width-2 generate
        binInput(i) <= binInput(i+1) xor input(i);
    end generate;
    
    -- encoder
    output(width-1) <= currentState(width-1);
    genEncoder:
    for i in 0 to width-2 generate
        output(i) <= currentState(i+1) xor currentState(i);
    end generate;

end architecture;
