function [x, M] = fraizes(a)
    n = length(a) - 1;
    k = 0;
    while n > 0 
        k = k + 1;
        %x inicial
        r = 1 + max(abs(a(2:n+1))) / abs(a(1));
        xi(k) = complex(0.1 * r, 0.1 * r);
        
        %x final
        [x(k), M(k)] = fnewtonPolinomio(n, a, xi(k));
        
        %reducao de grau
        [n, a] = freduzirGrau(x(k), M(k), n, a);
    end
endfunction

