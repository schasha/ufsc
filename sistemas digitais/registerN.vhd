library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity registerN is
	generic(	width: natural;
				resetValue: integer := 0 );
	port(	-- control
			clock, reset, load: in std_logic;
			-- data
			input: in std_logic_vector(width-1 downto 0);
			output: out std_logic_vector(width-1 downto 0));
end entity;

architecture behav0 of registerN is
signal currentState, nextState: std_logic_vector(width-1 downto 0);
begin
	-- logica de proximo estado
	nextState <= input when load = '1' else
	             currentState;
	
	-- estado interno (registrador)
	process(clock, reset)
	begin 
	    if reset = '1' then 
	        currentState <= std_logic_vector(to_unsigned(resetValue, input'length));
	    elsif rising_edge(clock) then
	        currentState <= nextState;
	    end if;
	end process;
	
	-- logicas de saida
	output <= currentState;
end architecture;