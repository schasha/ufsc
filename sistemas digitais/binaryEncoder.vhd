library ieee;
use ieee.std_logic_1164.all;
use ieee.math_real.all;
use ieee.numeric_std.all;

entity binaryEncoder is
	generic(inputWidth: positive;
			priorityMSB: boolean;
			generateValid: boolean );
	port(input: in std_logic_vector(inputWidth-1 downto 0);
		valid: out std_logic;
		output: out std_logic_vector(integer(ceil(log2(real(inputWidth))))-1 downto 0) );
end entity;

architecture behav0 of binaryEncoder is
begin

ifValidGen:
if generateValid generate
    valid <= '0' when to_integer(unsigned(input)) = 0 else
             '1';
end generate;

ifPriority:
if priorityMSB generate
    process(input)
        variable count, index: unsigned(output'range);
    begin
        count := (others => '0');
        index := (others => '0');
        for i in 0 to input'high loop
            if input(i) = '1' then
                index := count;
            end if;
            count := count + 1;
        end loop;
        output <= std_logic_vector(index);
    end process;
end generate;

ifNotPriority:
if not priorityMSB generate
    process(input)
        variable count, index: unsigned(output'range);
    begin
        count := (others => '1');
        index := (others => '0');
        for i in input'high downto 0 loop
            if input(i) = '1' then
                index := count;
            end if;
            count := count - 1;
        end loop;
        output <= std_logic_vector(index);
    end process;
end generate;

end architecture;