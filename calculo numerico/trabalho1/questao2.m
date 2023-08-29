function x = questao2()

%2.1.a)

A = zeros(50);
B = zeros(50, 1);

n1=15; n2=25; n3=50;

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

endfunction 
