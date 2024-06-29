-- -------- Aula 6 Exercicio 4 evolução 2 --------
--
--                    SCRIPT DE CONSULTA (DML)
--
-- Data Criacao ...........: 28/05/2024
-- Autor(es) ..............: Caio Felipe Rocha Rodrigues e Gabryel Nícolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula6exer4evolucao2
--
-- PROJETO => 01 Base de Dados
--         => 05 Tabelas
-- 
-- Ultimas Alteracoes
--   17/06/2024 => Primeira versao das consultas
--
-- ---------------------------------------------------------

USE aula6exer4evolucao2;

SELECT e.*
FROM EMPREGADO e
JOIN DEPARTAMENTO d ON e.idSupervisor = d.idSupervisor
WHERE d.nome = 'Tecnologia da Informação';

SELECT d.codigo, d.nome, e.nome AS gerente
FROM DEPARTAMENTO d
LEFT JOIN EMPREGADO e ON d.idSupervisor = e.idPessoa;

SELECT *
FROM EMPREGADO
WHERE dataNascimento BETWEEN '1990-01-01' AND '2000-12-31';

CREATE VIEW DepartamentoProjetos AS
SELECT d.codigo, d.nome, COUNT(p.idProjeto) AS quantidadeProjetos
FROM DEPARTAMENTO d
LEFT JOIN PROJETO p ON d.codigo = p.idDepartamento
GROUP BY d.codigo, d.nome;

SELECT * FROM DepartamentoProjetos;

SELECT * FROM DepartamentoProjetos WHERE nome = 'Tecnologia da Informação';
