function M = fgetM(R)
    M = 1;
    somaRestos = sum(abs(R(1:2)));
    while somaRestos < 10e-11
        M = M + 1;
        somaRestos = somaRestos + abs(R(M+1));
    end
endfunction
