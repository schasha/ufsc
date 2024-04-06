library ieee;
use ieee.std_logic_1164.all;

entity multiplierCR is
	generic(N: positive := 4);
	port(   
	    a, b: in std_logic_vector(N-1 downto 0);
		y: out std_logic_vector(2*N-1 downto 0) 
	);
end entity;

architecture structure of multiplierCR is
	component fulladder1bit is
		port(
			cin, a, b: in std_logic;
			sum: out std_logic;
			cout: out std_logic
		);
	end component;
    type matriz2d is array(N-1 downto 0) of std_logic_vector(N downto 0);
	signal s, c, ab: matriz2d;
	-- para acessar, por exemplo, s[i,j], use: s(i)(j)
begin

    -- gera produto de bits a.b
gen_a:
for i in a'range generate
    gen_b:
    for j in b'range generate
        ab(i)(j) <= a(i) and b(j);
    end generate;
end generate;

gen_linhas:
for i in 1 to N-1 generate
    gen_colunas:
    for j in 0 to N-1 generate
    
        gen_1_linha:
        if i = 1 generate
            gen_adder_1_0:
            if j = 0 generate
                fulladder_1_0: fulladder1bit port map(  cin => '0',
                                                        a => ab(i)(j),
                                                        b => ab(i-1)(j+1),
                                                        sum => y(i),
                                                        cout => c(i)(j+1) );
            end generate;
            
            gen_adder_1_Nm1:
            if j = N-1 generate
                fulladder_1_Nm1: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => '0',
                                                        sum => s(i)(j),
                                                        cout => c(i)(j+1) );
            end generate;
            
            gen_adder_1_meio:
            if (j /= N-1) and (j /= 0) generate
                fulladder_1_meio: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => ab(i-1)(j+1),
                                                        sum => s(i)(j),
                                                        cout => c(i)(j+1) );
            end generate;
        end generate;
        
        gen_Nm1_linha:
        if i = N-1 generate
            gen_adder_Nm1_0:
            if j = 0 generate
                fulladder_Nm1_0: fulladder1bit port map(cin => '0',
                                                        a => ab(i)(j),
                                                        b => s(i-1)(j+1),
                                                        sum => y(i),
                                                        cout => c(i)(j+1) );
            end generate;
            
            gen_adder_Nm1_Nm1:
            if j = N-1 generate
                fulladder_Nm1_Nm1: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => c(i-1)(j+1),
                                                        sum => y(i+j),
                                                        cout => y(i+j+1) );
            end generate;
            
            gen_adder_Nm1_meio:
            if (j /= N-1) and (j /= 0) generate
                fulladder_Nm1_meio: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => s(i-1)(j+1),
                                                        sum => y(i+j),
                                                        cout => c(i)(j+1) );
            end generate;
        end generate;
        
        gen_meio_linhas:
        if (i /= N-1) and (i /= 1) generate
            gen_meio_0:
            if j = 0 generate
                fulladder_meio_0: fulladder1bit port map(cin => '0',
                                                        a => ab(i)(j),
                                                        b => s(i-1)(j+1),
                                                        sum => y(i),
                                                        cout => c(i)(j+1) );
            end generate;
                
            gen_meio_Nm1:
            if j = N-1 generate
                fulladder_meio_Nm1: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => c(i-1)(j+1),
                                                        sum => s(i)(j),
                                                        cout => c(i)(j+1) );
            end generate;
            
            gen_meio_meio:
            if (j /= N-1) and (j /= 0) generate
                fulladder_meio_meio: fulladder1bit port map(cin => c(i)(j),
                                                        a => ab(i)(j),
                                                        b => s(i-1)(j+1),
                                                        sum => s(i)(j),
                                                        cout => c(i)(j+1) );
            end generate;
        end generate;
        
    end generate;
end generate;

y(0) <= ab(0)(0);

end architecture;