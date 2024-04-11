function R = frestos(n, a, xi)
    n_inicial = n;
    %briot-ruffini
    for k = 1:n_inicial
        b(1) = a(1);
        for i = 2:n+1
            b(i) = a(i) + xi * b(i-1);
        end
        R(k) = b(n+1);
        
        %"reduz grau"
        n = n-1;
        a = b(1:n+1);
    end
    R(n_inicial+1) = a(1);
endfunction

