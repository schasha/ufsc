library ieee;
use ieee.std_logic_1164.all;
use ieee.math_real.all;
use ieee.numeric_std.all;

entity moduleCounter is
	generic(	module: positive := 60;
				generateLoad: boolean := true;
				generateEnb: boolean := true;
				generateInc: boolean := true;
				resetValue: integer := 0 );
	port(	-- control
			clock, reset: in std_logic;
			load, enb, inc: in std_logic;
			-- data
			input: in std_logic_vector(integer(ceil(log2(real(module))))-1 downto 0);
			output: out std_logic_vector(integer(ceil(log2(real(module))))-1 downto 0)	);
end entity;


architecture behav0 of moduleCounter is
    subtype state is unsigned(integer(ceil(log2(real(module))))-1 downto 0);
    signal nextState, currentState: state;
    signal tempNextState, tempNextState2: state;
    signal modUnsig: state;
begin
	-- next-state logic
	modUnsig <= to_unsigned(module, input'length);
	
	genLoad:
    if generateLoad generate
        tempNextState2 <= unsigned(input) when load = '1' else
                          tempNextState;
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
        tempNextState <= currentState + 1 when inc = '1' and currentState /= modUnsig-1 else
             to_unsigned(0, input'length) when inc = '1' and currentState = modUnsig-1 else
                         currentState - 1 when inc = '0' and currentState /= 0 else
                               modUnsig-1 when inc = '0' and currentState = 0;
    end generate;
    
    genNotInc:
    if not generateInc generate
        tempNextState <= currentState + 1 when currentState /= modUnsig-1 else
             to_unsigned(0, input'length) when currentState = modUnsig-1;
    end generate;
	
	-- memory register
	process(clock, reset) is
	begin
		if reset='1' then
			currentState <= (to_unsigned(resetValue, currentState'length));
		elsif rising_edge(clock) then
			currentState <= nextState;
		end if;
	end process;
	
	-- output-logic
    output <= std_logic_vector(currentState);

end architecture;