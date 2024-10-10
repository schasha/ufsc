CREATE TABLE Ambulatorios (nroa int, andar numeric(2) NOT null, capacidade smallint, PRIMARY KEY(nroa));

CREATE TABLE Medicos (codm int, nome varchar(40) NOT null, idade smallint NOT null, cidade varchar(40), CPF numeric(11) NOT null unique, especialidade varchar(30), nroa int, PRIMARY KEY(codm), FOREIGN KEY(nroa) REFERENCES Ambulatorios);

CREATE TABLE Pacientes (codp int, nome varchar(40) NOT null, idade smallint NOT null, cidade varchar(40), CPF numeric(11) NOT null unique, doenca varchar(40) NOT null, PRIMARY KEY(codp));

CREATE TABLE Funcionarios (codf int, nome varchar(40) NOT null, idade smallint NOT null, cidade varchar(40), CPF numeric(11) NOT null unique, salario numeric(10), PRIMARY KEY(codf));

CREATE TABLE Consultas (codm int, codp int, data date, hora time, PRIMARY KEY(codm, codp, data), FOREIGN KEY(codm) REFERENCES Medicos, FOREIGN KEY(codp) REFERENCES Pacientes);

INSERT INTO Pacientes 
       VALUES (1, 'Ana', 20, 'Florianopolis', 20000200000, 'gripe'),
              (2, 'Paulo', 24, 'Palhoca', 20000220000, 'fratura'),
              (3, 'Lucia', 30, 'Biguacu', 22000200000, 'tendinite'),
              (4, 'Carlos', 28, 'Joinville', 11000110000, 'sarampo');

INSERT INTO Ambulatorios
       VALUES (1, 1, 30),
              (2, 1, 50),
              (3, 2, 40),
              (4, 2, 25),
              (5, 2, 55);

INSERT INTO Medicos
       VALUES (1, 'Joao', 40, 'Florianopolis', 10000100000, 'ortopedia', 1),
              (2, 'Maria', 42, 'Blumenau', 10000110000, 'traumatologia', 2),
              (3, 'Pedro', 51, 'Sao Jose', 11000100000, 'pediatria', 2),
              (4, 'Carlos', 28, 'Joinville', 11000110000, 'ortopedia', NULL),
              (5, 'Marcia', 33, 'Biguacu', 11000111000, 'neurologia', 3);

INSERT INTO Funcionarios
       VALUES (1, 'Rita', 32, 'Sao Jose', 20000100000, 1200),
              (2, 'Vera', 55, 'Palhoca', 30000110000, 1220),
              (3, 'Caio', 45, 'Florianopolis', 41000100000, 1100),
              (4, 'Marcelo', 44, 'Florianopolis', 51000110000, 1200),
              (5, 'Paula', 33, 'Florianopolis', 61000111000, 2500);

INSERT INTO Consultas
        VALUES (1, 1, '2020/10/12', '14:00'),
               (1, 4, '2020/10/13', '10:00'),
               (2, 1, '2020/10/13', '9:00'),
               (2, 2, '2020/10/13', '11:00'),
               (2, 3, '2020/10/14', '14:00'),
               (2, 4, '2020/10/14', '17:00'),
               (3, 1, '2020/10/19', '18:00'),
               (3, 3, '2020/10/12', '10:00'),
               (3, 4, '2020/10/10', '13:00'),
               (4, 4, '2020/10/20', '13:00'),
               (4, 4, '2020/10/22', '19:30');
