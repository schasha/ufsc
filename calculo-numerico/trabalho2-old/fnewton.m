function raizes = fnewton(f, dominio)
    %localizacao
    numero_de_intervalos = 1000;
    
    h = (dominio(2) - dominio(1))/numero_de_intervalos;
    x = dominio(1):h:dominio(2);
    y = f(x);

    indice_raiz = 0;
    limite=0.1/h;
    for i = 1:length(x) - 1
        if (y(i) * y(i + 1)) <= 0 && abs(y(i) - y(i+1)) < limite
            indice_raiz++;
            xi(indice_raiz) = (x(i) + x(i + 1)) * 0.5;
        end    
    end

    %metodo de newton para cada raiz 
    for i = 1 : length(xi)
        delta_x = 1e-5;
        repeticoes = 0;
        while abs(delta_x) > 1e-15 && repeticoes < 100
            repeticoes++;

            derivada_f = (f(xi(i) + delta_x) - f(xi(i)))/delta_x;
            
            delta_x = - f(xi(i))/derivada_f;
            raizes(i) = xi(i) + delta_x;
            xi(i) = raizes(i);
        end
    end
    
endfunction
