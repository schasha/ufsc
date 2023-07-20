library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

entity arbitraryCounter is
	generic(min: natural;
	        max: natural;
	        step: natural;
			generateLoad: boolean;
			generateEnb: boolean;
			generateInc: boolean);
	port(	-- control
			clock, reset, load: in std_logic;
			enb, inc: in std_logic;
			-- data
			input: in std_logic_vector(integer(ceil(log2(real(max))))-1 downto 0);
			output: out std_logic_vector(integer(ceil(log2(real(max))))-1 downto 0)	);
	begin
		assert min<max report "Min should be smaller than max" severity error;
		assert step<(max-min) report "Step should be smaller than the max-min interval" severity error;
end entity;


architecture behav0 of arbitraryCounter is
    subtype state is unsigned(integer(ceil(log2(real(max))))-1 downto 0);
    signal nextState, currentState: state;
    signal tempNextState, tempNextState2: state;
    signal tempMin, tempMax, tempStep: state;
begin
	-- next-state logic
	tempMin <= to_unsigned(min, input'length);
	tempMax <= to_unsigned(max, input'length);
	tempStep <= to_unsigned(step, input'length);
	genLoad:
    if generateLoad generate
        tempNextState2 <= unsigned(input) when load = '1' else
                          tempNextState;
    end generate;
   
    genLoadWhenNotEnb:
    if generateLoad and not generateEnb generate
        tempNextState <= unsigned(input) when load = '1' else
                         nextState;
    end generate;
    
    genEnbWhenLoad:
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
        tempNextState <= currentState + tempStep when inc = '1' and currentState+tempStep <= tempMax else
                                         tempMin when inc = '1' and currentState+tempStep > tempMax else
                         currentState - tempStep when inc = '0' and currentState-tempStep >= tempMin else
                                         tempMax when inc = '0' and currentState-tempStep < tempMin;
    end generate;
    
    genNotInc:
    if not generateInc generate
        tempNextState <= currentState + tempStep when currentState+tempStep <= tempMax else
                                         tempMin when currentState+tempStep > tempMax;
    end generate;
	
	-- memory register (DO NOT CHANGE OR REMOVE THIS LINE)
	process(clock, reset) is
	begin
		if reset='1' then
			currentState <= tempMin;
		elsif rising_edge(clock) then
			currentState <= nextState;
		end if;
	end process;
		
	-- output-logic (DO NOT CHANGE OR REMOVE THIS LINE)
    output <= std_logic_vector(currentState);
 
end architecture;