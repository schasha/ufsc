library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity absN is
	generic(	width: positive );
	port(	input: in std_logic_vector(width-1 downto 0);
			output: out std_logic_vector(width-1 downto 0) );
end entity;

architecture behav0 of absN is
signal inp, outp: signed(width-1 downto 0);
begin
    inp <= signed(input);
    process(inp)
    begin
        outp <= (others => '0');
        if inp < 0 then
            outp <= -inp;
        else
            outp <= inp;
        end if;
    end process;
    output <= std_logic_vector(outp);
end architecture;