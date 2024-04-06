function [x, M] = fnewtonPolinomio(n, a, xi)
    delta_x = 1;
    iteracao = 0;
    while abs(delta_x) > 1e-15 && iteracao < 100
        iteracao++;
        R = frestos(n, a, xi);
        M = fgetM(R);

        delta_x = - R(M) / (M * R(M+1));
        x = xi + delta_x;
        xi = x;
    end
endfunction

