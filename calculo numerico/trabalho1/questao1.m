function x = questao1()
%a
printf("a)\n")

single_a = single(-20.125);
printf("single = 1|10000011|01000010000000000000000\n")
s = 1
printf("e = 10000011\n")
printf("f = 01000010000000000000000\n")

printf("\n")

double_a = -20.125;
printf("double = 1|10000000011|0100001000000000000000000000000000000000000000000000\n")
s = 1
printf("e = 10000000011\n")
printf("f = 0100001000000000000000000000000000000000000000000000\n")

printf("\n")

printf("single = %.20f\n", single_a)
printf("double = %.20f\n", double_a)
printf("\n")
format long
erro = abs(double(single(-20.125)) - (-20.125))/(-20.125)
format short
%b
printf("\n")
printf("b)\n")

single_b = single(-60.06);
printf("single = 1|10000100|11100000011110101110001\n")
s = 1
printf("e = 10000100\n")
printf("f = 11100000011110101110001\n")

printf("\n")

double_b = -60.06;
printf("double = 1|10000000100|1110000001111010111000010100011110101110000101001000\n")
s = 1
printf("e = 10000000011\n")
printf("f = 1110000001111010111000010100011110101110000101001000\n")

printf("\n")

printf("single = %.20f\n", single_b)
printf("double = %.20f\n", double_b)
printf("\n")
format long
erro = abs(double(single(-60.06)) - (-60.06))/(-60.06)
format short

endfunction
