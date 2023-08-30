function [X, operacoes] = fgauss_seidel(A, B)
    n = size(A, 1);
    % Busca os indices j originais dos coeficientes nao nulos de cada linha i em NN(i,..)
    for i = 1 : n
        nao_nulos_total(i) = 0; %Numero Total de coeficientes vizinhos nao nulos
        % Percorre os valores anteriores ao coeficiente da diagonal principal
        for j = 1 : i - 1
            if abs(A(i, j)) > 1e-14
               nao_nulos_total(i) += 1; %Numero Total de coeficientes vizinhos nao nulos
               NN(i, nao_nulos_total(i))=j; %indices j originais dos coeficientes nao nulos de cada linha i
            end
        end
        
        % Percorre os valores posteriores ao coeficiente da diagonal principal
        for j = i + 1 : n
            if abs(A(i, j)) > 1e-14
               nao_nulos_total(i) += 1; %Numero Total de coeficientes vizinhos nao nulos
               NN(i, nao_nulos_total(i))=j;%indices j originais dos coeficientes nao nulos de cada linha i
            end
        end
        
    end

    % Utiliza os valores disponíveis
    X = zeros(n, 1);
    diferenca = 1;
    k = 0;
    operacoes = 0;
    lambda = 1.01; % Fator de relaxacao otimo para este exemplo
    while diferenca > 1e-10 && k < 100
        k = k + 1;
        X_anterior = X;
        for i=1:n
            %i
                c=1:nao_nulos_total(i);   %indice de ordem novo das Colunas 
            % _NN=NN(i,c) %indice de ordem original das Colunas 
            % _A =A(i, NN(i,c))
            % _x =x(NN(i,c),1)
            X(i) = (1-lambda)*X_anterior(i)+lambda*(B(i,1) - sum(A(i, NN(i,c))*X(NN(i,c),1)))/A(i,i);
            operacoes++;
        end
        diferenca = max(abs(X - X_anterior));
    end

endfunction

