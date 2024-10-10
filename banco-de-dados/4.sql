SELECT medicos.nome, medicos.cpf
FROM medicos JOIN 
pacientes
ON pacientes.cpf = medicos.cpf

SELECT medicos.nome, funcionarios.nome
FROM medicos JOIN
funcionarios
ON funcionarios.cidade = medicos.cidade

SELECT medicos.nome, medicos.idade
FROM medicos JOIN
consultas
ON medicos.codm = consultas.codm
JOIN
pacientes
ON pacientes.codp = consultas.codp
WHERE pacientes.nome = 'Ana'

SELECT COUNT(a1.nroa)
FROM ambulatorios a1 JOIN
ambulatorios a2
ON a2.nroa = 5 AND a1.andar = a2.andar

SELECT pacientes.codp, pacientes.nome
FROM pacientes NATURAL JOIN
consultas
WHERE consultas.hora > '14:00'

SELECT ambulatorios.andar, ambulatorios.nroa
FROM ambulatorios NATURAL JOIN
medicos
NATURAL JOIN
consultas
WHERE consultas.data > '2020-10-12'

SELECT medicos.nome, medicos.codm, ambulatorios.nroa
FROM ambulatorios LEFT JOIN
medicos
ON medicos.nroa = ambulatorios.nroa

SELECT medicos.nome, medicos.cpf, pacientes.nome, consultas.data
FROM medicos LEFT JOIN
consultas
ON medicos.codm = consultas.codm
JOIN
pacientes
ON pacientes.codp = consultas.codp
