function [n, a] = freduzirGrau(x, M, n, a)
    %reducao de grau por briot rufini
    for k = 1:M
        b(1) = a(1);
        for i = 2:n+1
            b(i) = a(i) + x * b(i-1);
        end
        n = n-1;
        a = b(1:n+1);
    end
endfunction

