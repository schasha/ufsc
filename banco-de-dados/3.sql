SELECT *
FROM Medicos
WHERE idade < 40 or especialidade != 'traumatologia'

SELECT nome, idade
FROM pacientes
WHERE cidade != 'Florianopolis'

SELECT nome, idade * 12
FROM pacientes

SELECT MAX(hora)
FROM consultas
WHERE data = '2020-10-13'

SELECT AVG(idade), COUNT(distinct nroa)
FROM medicos

SELECT codf, nome, 0.8 * salario
FROM funcionarios

SELECT nome
FROM funcionarios
WHERE nome like '%a'

SELECT nome, especialidade
FROM medicos
WHERE nome like '_o%o'

SELECT codp, nome
FROM pacientes
WHERE idade > 25
and doenca in ('tendinite',
		'fratura',
		'gripe',
		'sarampo')

SELECT cpf, nome, idade
FROM medicos
WHERE cidade = 'Florianopolis'
UNION
SELECT cpf, nome, idade
FROM funcionarios
WHERE cidade = 'Florianopolis'
UNION
SELECT cpf, nome, idade
FROM pacientes 
WHERE cidade = 'Florianopolis'
