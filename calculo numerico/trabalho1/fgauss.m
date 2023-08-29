function x=fgauss(n,A)

%Escalonamento
	for k=1:n-1
    %Escolhe a melhor linha i=k, antes de efetuar a eliminacao
		for i=k+1:n
			aux=A(i,k)/A(k,k);
			for j=k+1:n+1  %operações com mínimo de colunas 
				A(i,j)=A(i,j)-aux*A(k,j);
			end %for j
			A(i,k)=0; %valor exato
		end %for i
	end %for k

%Retrosubstituição
	x(n)=A(n,n+1)/A(n,n);
	for i=n-1:-1:1 % calculos a partir da penultima equação
		soma=0;
		for j=i+1:n
			soma=(A(i,j)*x(j))+soma;
		end
		x(i)=(A(i,n+1)-soma)/A(i,i);
	end

x = transpose(x);

endfunction 
