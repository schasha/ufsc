function x = questao1()
%a)
printf("a)\n")

printf("sin(x)^3 * cos(x)^3+0.1 = 0 no subdominio [-6; 6]\n\n")
f = @(x) (sin(x).^3 .* cos(x).^3 + 0.1);
subdominio = [-6 6];

raizes = fnewton(f, subdominio);
for i = 1:length(raizes)
    printf("Raiz %d: ", i)
    raizes(i)
    printf("Residuo %d: ", i)
    f(raizes(i))
    printf("\n")
end

%b)

printf("b)\n")

printf("x^4 - 2*i x^3 - 1.5 x^2 + (0.5*i) x + 0.0625\n\n")
coeficientes = [1, -2i, -1.5, 0.5i, 0.0625];

raizes = fraizes(coeficientes);
for i = 1:length(raizes)
    printf("Raiz %d: ", i)
    raizes(i)
    printf("Residuo %d: ", i)
    fvalorPolinomio(coeficientes, raizes(i))
    printf("\n")
end

for (i = length(raizes):-1:2)
    printf("(x - (%d %+f*i)) * ", real(raizes(i)), imag(raizes(i)))
end
printf("(x - (%d %+f*i))\n\n", real(raizes(1)), imag(raizes(1)))

%c)

printf("c)\n")

printf("x^8 - 11.3 x^7 + 50.83 x^6 - 114.581 x^5 + 132.9985 x^4 - 72.57875 x^3 + 14.865625 x^2 - 1.2734375 x + 0.0390625 = 0\n\n")
coeficientes = [1, -11.3, 50.83, -114.581, 132.9985, -72.57875, 14.865625, -1.2734375, 0.0390625];

raizes = fraizes(coeficientes);
for i = 1:length(raizes)
    printf("Raiz %d: ", i)
    raizes(i)
    printf("Residuo %d: ", i)
    fvalorPolinomio(coeficientes, raizes(i))
    printf("\n")
end

for (i = length(raizes):-1:2)
    printf("(x - (%d %+f*i)) * ", real(raizes(i)), imag(raizes(i)))
end
printf("(x - (%d %+f*i))\n\n", real(raizes(1)), imag(raizes(1)))

%d)

printf("d)\n")

printf("x^8 - 1.3 x^7 + 0.83 x^6 - 0.681 x^5 + 0.2285 x^4 - 0.09675 x^3 + 0.021125 x^2 - 0.0019375 x + 0.0000625 = 0\n\n")
coeficientes = [1, -1.3, 0.83, -0.681, 0.2285, -0.09675, 0.021125, 0.0019375, 0.0000625];

raizes = fraizes(coeficientes);
for i = 1:length(raizes)
    printf("Raiz %d: ", i)
    raizes(i)
    printf("Residuo %d: ", i)
    fvalorPolinomio(coeficientes, raizes(i))
    printf("\n")
end

for (i = length(raizes):-1:2)
    printf("(x - (%d %+f*i)) * ", real(raizes(i)), imag(raizes(i)))
end
printf("(x - (%d %+f*i))\n\n", real(raizes(1)), imag(raizes(1)))

endfunction
