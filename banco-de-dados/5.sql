SELECT nome
FROM pacientes
WHERE codp IN 
(SELECT codp
 FROM consultas
 WHERE hora > '14:00')

SELECT nome, idade
FROM medicos
WHERE codm IN
 (SELECT codm
  FROM consultas
  WHERE codp IN
   (SELECT codp
    FROM pacientes
    WHERE nome = 'Ana'))

SELECT nroa, andar
FROM ambulatorios
WHERE nroa NOT IN
 (SELECT nroa
  FROM medicos
  WHERE nroa IS NOT NULL)

SELECT cpf
FROM medicos
WHERE nroa = SOME
 (SELECT nroa
  FROM ambulatorios
  WHERE andar = 1)

SELECT nome, cpf
FROM funcionarios
WHERE salario > SOME
 (SELECT salario
  FROM funcionarios)

SELECT nome
FROM pacientes
WHERE codp = SOME
 (SELECT codp
  FROM consultas
  WHERE hora < ALL
  (SELECT hora
   FROM consultas
   WHERE data = '2020-10-14'))

SELECT nroa, andar
FROM ambulatorios
WHERE capacidade > SOME
 (SELECT capacidade
  FROM ambulatorios
  WHERE andar = 1)
