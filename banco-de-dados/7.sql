SELECT *
FROM Funcionarios
ORDER BY salario DESC, nome ASC
LIMIT 3;

SELECT nome, codm, nroa
FROM Medicos
ORDER BY nroa;

SELECT andar, SUM(capacidade)
FROM Ambulatorios
GROUP BY andar;

SELECT andar
FROM Ambulatorios
GROUP BY andar HAVING AVG(CAPACIDADE) >= 40;

SELECT m.nome
FROM (SELECT nome, codm FROM medicos) AS m
JOIN Consultas AS c ON m.codm = c.codm
GROUP BY m.nome HAVING COUNT(c.codm); > 1;

DELETE FROM Ambulatorios
WHERE nroa NOT IN
(SELECT nroa FROM Medicos WHERE nroa IS NOT NULL);

UPDATE Medicos
SET
cidade = (SELECT cidade FROM Pacientes WHERE nome LIKE '%Paulo%'),
idade = 2*(SELECT idade FROM Pacientes WHERE nome LIKE '%Ana%')
WHERE nome LIKE '%Pedro%';

INSERT INTO Medicos VALUES
(6,
(SELECT nome FROM Funcionarios WHERE codf = 3),
(SELECT idade FROM Funcionarios WHERE codf = 3),
(SELECT especialidade FROM Medicos WHERE codm = 2),
(SELECT CPF FROM Funcionarios WHERE codf = 3),
(SELECT cidade FROM Funcionarios WHERE codf = 3),
NULL);
