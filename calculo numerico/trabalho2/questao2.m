function questao2()

printf("f1(x(1),x(2),x(3))=sin(x(1))*cos(x(2))+x(3)-1.5=0\n")
printf("f2(x(1),x(2),x(3))= x(1)^2+x(2)^2+x(3)^2-3.0=0\n")
printf("f3(x(1),x(2),x(3))= x(1)+x(2)+x(3)-3.1=0\n\n")

g1 = @(x) sin(x(1)) * cos(x(2)) + x(3) - 1.5;
g2 = @(x) x(1)*x(1) + x(2)*x(2) + x(3)*x(3) - 3.0;
g3 = @(x) x(1) + x(2) + x(3) - 3.1;

printf("solucao 1\n")
wi = [complex(-1,1); complex(1,1); complex(1,1)];
w = fnewton3Matrix(wi, g1, g2, g3)
res_max_w = max(abs([g1(w); g2(w); g3(w)]))
printf("\n")

printf("solucao 2\n")
zi = [complex(-1,1); complex(0.5,1); complex(0.5,1)];
z = fnewton3Matrix(zi, g1, g2, g3)
res_max_z = max(abs([g1(z); g2(z); g3(z)]))

endfunction
