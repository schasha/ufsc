A = zeros(50);
B = zeros(50, 1);
AB = [A B];

n1=15; n2=25; n3=50;

i=1
    AB(i) = [3*x(i)    + 2*x(i+5)                       +2

for i=2:n1-1
    AB(i) =   x(i-1)  + 3*x(i)   + 2*x(i+5)           -2 

for i=n1:n2-1
    AB(i) = 2*x(i-4)  + 4*x(i)   +   x(i+1)            +3 

i=n2
    AB(i) =   x(i-1)  + 6*x(i)   -   x(i+4)           -2

for i=n2+1:n3-1
    AB(i) =   x(i-3)  +   x(i-1) + 7*x(i) + 2*x(i+1)    +5

i=n3            
    AB(i) = 2*x(i-10) + 5*x(i)                        -5
