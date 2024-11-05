CREATE VIEW FloripaView
 (codf, nome, cpf, idade)
  AS SELECT codf, nome, cpf, idade
     FROM Funcionarios
     WHERE cidade = 'Florianopolis';


UPDATE FloripaView
SET idade = idade + 1;

-- sim, a atualizacao funcionou

INSERT INTO FloriaView
 VALUES (10, 'Rodrigo', 22200022233, 41);

-- nao, a atualizacao na visao falhou mas na tabela funcionou, pois o campo cidade nao esta preenchido

CREATE RULE InsercaoFlorianopolis
AS ON INSERT TO FloripaView
DO INSTEAD
 INSERT INTO Funcionarios (codf, nome, idade, cidade, CPF)
 VALUES (NEW.codigo, NEW.nome, NEW.idade, 'Florianopolis', NEW.CPF);


INSERT INTO FloriaView
 VALUES (11, 'Raul', 44400044433, 53);

-- agora, com o trigger, a atualizacao na tabela e na visao funcionaram

CREATE VIEW AmbulatorioMaior2
 (codm, nome, idade, cpf, nroa)
  AS SELECT codm, nome, idade, cpf, nroa
     FROM Medicos
     WHERE nroa >= 2
  WITH CHECK OPTION;


INSERT INTO AmbulatorioMaior2
 VALUES (7, 'Soraia', 47, 55500055533, 2);

-- sim, a atualizacao funcionou.

INSERT INTO AmbulatorioMaior2
 VALUES (8, 'Saulo', 47, 66600066633, 1);

-- nao, a atualizacao nao fucionou, pois o numero do ambulatorio eh menor que 2
