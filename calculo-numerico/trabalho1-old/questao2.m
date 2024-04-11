function x = questao2()

%2.1.a)

A = zeros(50);
B = zeros(50, 1);

n1=15; n2=25; n3=50;
n = n3;

%i=1
    A(1, 1) = 3;
    A(1, 6) = 2;
    B(1, 1) = 2;

%i=n2
    A(25, 24) = 1;
    A(25, 25) = 6;
    A(25, 29) = -1;
    B(25, 1)  = -2;

%i=n3
    A(50, 40) = 2;
    A(50, 50) = 5;
    B(50, 1)  = -5;

for i=2: n1-1
    A(i, i-1) = 1;
    A(i, i)   = 3;
    A(i, i+5) = 2;
    B(i, 1)   = -2;
end

for i=n1: n2-1
    A(i, i-4) = 2;
    A(i, i)   = 4;
    A(i, i+1) = 1;
    B(i, 1)   = 3;
end

for i=n2+1: n3-1
    A(i, i-3) = 1;
    A(i, i-1) = 1;
    A(i, i)   = 7;
    A(i, i+1) = 2;
    B(i, 1)   = 5;
end

%2.1.b)

A_expandida = [A B];

x = fgauss(n, A_expandida);

printf("Solucao pelo metodo direto:\n")
transpose(x)

residuo = [A*x - B];
residuo_max = max(residuo)

%2.1.c)

operacoes_realizadas = (4*(n^3) + 9*(n^2) - n - 6)/6
printf("\n")

%2.2.a)

printf("Teste de convergencia\n")
c = true;

for (i = 1:n)
    soma = 0;
    for j=1:n
        soma = soma + abs(A(i, j));
    end
    v = abs(A(i,i));
    soma = soma - v;

    if (v > soma)
        cond_b = true;
        printf("|%d| > |%d| V \n", A(i,i), soma)

    elseif (v >= soma)
        printf("|%d| >= |%d| V \n", A(i,i), soma)

    else
        c = false;
        printf("|%d| >= |%d| F \n", A(i,i), soma)
    end

end

if c == 1
    if (cond_b == 1)
        printf("Sistema convergente, pois possui diagonal dominante ")
        printf("ou seja, para todo A(i,i) vale que A(i,i) >= Zi (i = 1, ... , n) ")
        printf("e ainda, para pelo menos um A(i,i) vale A(i,i) > Zi (i = 1, ..., n)\n")
    else
    	printf("Sistema nao convergente, nao possui diagonal dominante\n")
    end
end
printf("\n")

%2.2.b)

[y, operacoes] = fgauss_seidel(A, B);

printf("Solucao pelo metodo iterativo:\n")
transpose(y)

residuo = [A*y - B];
residuo_max = max(residuo)

%2.2.c)

operacoes

endfunction 
