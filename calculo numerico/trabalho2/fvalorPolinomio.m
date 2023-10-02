function R = fvalorPolinomio(a, x)
    n = length(a) - 1;
    for k = 1:length(x)
        b(1) = a(1);
        for i = 2:n+1
            b(i) = a(i) + x(k) * b(i-1);
        end
        R(k) = b(n+1);
    end
end

