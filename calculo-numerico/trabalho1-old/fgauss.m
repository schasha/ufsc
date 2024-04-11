function x=fgauss(n,A)

%Escalonamento
	for k=1:n-1
		for i=k+1:n
			aux=A(i,k)/A(k,k);
			for j=k+1:n+1
				A(i,j)=A(i,j)-aux*A(k,j);
			end
			A(i,k)=0; %valor exato
		end
	end

%Retrosubstituição
	x(n)=A(n,n+1)/A(n,n);
	for i=n-1:-1:1
		soma=0;
		for j=i+1:n
			soma=(A(i,j)*x(j))+soma;
		end
		x(i)=(A(i,n+1)-soma)/A(i,i);
	end

x = transpose(x);

endfunction 
