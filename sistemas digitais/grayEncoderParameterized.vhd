library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity grayEncoder is
	generic(width: natural);
	port(	binInput: in std_logic_vector(width-1 downto 0);
			grayOutput: out std_logic_vector(width-1 downto 0) );
end entity;

architecture concurrent_behav0 of grayEncoder is
signal j: std_logic_vector(width-1 downto 0);
begin
    grayOutput(width-1) <= binInput(width-1);
    gen:
    for i in 0 to width-2 generate
        grayOutput(i) <= binInput(i) xor binInput(i + 1);
    end generate;
end architecture;