library ieee;
use ieee.std_logic_1164.all;

entity shifterRotator is
	generic(
		width: positive;
		isShifter: boolean;
		isLogical: boolean;
		toLeft: boolean;
		bitsToShift: positive
	);
	port(
		input: in std_logic_vector(width-1 downto 0);
		output: out std_logic_vector(width-1 downto 0)
	);
	begin
		assert (bitsToShift < width) severity error;
end entity;

architecture behav of shifterRotator is
    signal widthBits, widthBits2, zeroBits, zeros, ones: std_logic_vector(bitsToShift-1 downto 0);
begin
    genVectors:
    for i in 0 to bitsToShift-1 generate
        widthBits(i) <= input(width-1-bitsToShift+1+i);
        zeroBits(i) <= input(i);
        widthBits2(i) <= input(width-1);
        zeros(i) <= '0';
        ones(i) <= '1';
    end generate;
    
    genRotatorLeft:
    if not isShifter and toLeft generate
        output <= input(width-1-bitsToShift downto 0) & widthBits;
    end generate;
    
    genRotatorRight:
    if not isShifter and not toLeft generate
        output <= zeroBits & input(width-1 downto bitsToShift);
    end generate;
    
    genShifterLeft:
    if isShifter and toLeft and isLogical generate
        output <= input(width-1-bitsToShift downto 0) & zeros;
	end generate;
	
	genShifterRight:
	if isShifter and not toLeft and isLogical generate
	    output <= zeros & input(width-1 downto bitsToShift);
	end generate;
	
	genArithmeticalShifterLeft:
	if isShifter and toLeft and not isLogical generate
	    output <= input(width-1-bitsToShift downto 0) & zeros;
	end generate;
	
	genArithmeticalShifterRight:
	if isShifter and not toLeft and not isLogical generate
	    output <= widthBits2 & input(width-1 downto bitsToShift);
	end generate;
	
end architecture;