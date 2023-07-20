library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity rippleCounter is
	generic(	width: positive := 8;
				generateLoad: boolean := true;
				generateEnb: boolean := true;
				generateInc: boolean := true);
	port(	-- control
			clock, reset: in std_logic;
			load, enb, inc: in std_logic;
			-- data
			input: in std_logic_vector(width-1 downto 0);
			output: out std_logic_vector(width-1 downto 0)	);
end entity;


architecture behav0 of rippleCounter is
    subtype state is unsigned(width-1 downto 0);
    signal nextState, currentState: state;
    signal tempNextState, tempNextState2, tempProcessState: state;
    signal wMax: state;
begin
	-- next-state logic
	genWMax:
	for i in 0 to width-1 generate
	    wMax(i) <= '1' when i = width-1 else
	               '0';
	end generate;
	
	genLoad:
    if generateLoad generate
        tempNextState2 <= unsigned(input) when load = '1' else
                          tempProcessState;
    end generate;
    
    genLoadNotEnb:
    if generateLoad and not generateEnb generate
        tempProcessState <= unsigned(input) when load = '1' else
                            nextState;
    end generate;
   
    genEnbLoad:
    if generateLoad and generateEnb generate
        nextState <= tempNextState2 when enb = '1' else
                     currentState;
    end generate;
    
    genEnb:
    if generateEnb and not generateLoad generate
        nextState <= tempProcessState when enb = '1' else
                     currentState;
    end generate;
    
    genNotEnb:
    if not generateEnb generate
        nextState <= tempProcessState;
    end generate;
    
    genInc:
    if generateInc generate
        tempNextState <= currentState(width-2 downto 0) & '0' when inc = '1' and currentState /= wMax else
                                 to_unsigned(1, input'length) when inc = '1' and currentState = wMax else
                         '0' & currentState(width-1 downto 1) when inc = '0' and currentState /= to_unsigned(1, input'length) else
                                                    wMax when inc = '0' and currentState = to_unsigned(1, input'length);
    end generate;
    
    genNotInc:
    if not generateInc generate
        tempNextState <= currentState(width-2 downto 0) & '0' when currentState /= wMax else
                                 to_unsigned(1, input'length) when currentState = wMax;
    end generate;
    
    tira1: 
        process(tempNextState)
        variable tempState: unsigned(width-1 downto 0);
        variable break: std_logic;
        begin
            break := '0';
            tempState := (others => '0');
            for i in tempNextState'range loop
                if tempNextState(i) = '1' and break = '0' then
                    break := '1';
                    tempState(i) := '1';
                end if;
                if break = '0' then
                    tempState(i) := '0';
                end if;
            end loop;
            tempProcessState <= tempState;
        end process;
	
	-- memory register
	process(clock, reset) is
	begin
		if reset='1' then
			currentState <= to_unsigned(1, currentState'length);
		elsif rising_edge(clock) then
			currentState <= nextState;
		end if;
	end process;
	
	-- output-logic
   	output <= std_logic_vector(currentState);

end architecture;