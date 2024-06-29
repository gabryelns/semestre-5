-- -------- Aula 6 Exercicio 4 evolução 2 --------
--
--                    SCRIPT DE CONSULTA (DML)
--
-- Data Criacao ...........: 17/06/2024
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

CREATE DATABASE IF NOT EXISTS aula6exer4evolucao2;
USE aula6exer4evolucao2;

CREATE ROLE 'administrador';

CREATE USER 'addbd' IDENTIFIED BY '123admin';
CREATE USER 'superr' IDENTIFIED BY 'admsuperR';
GRANT ALL PRIVILEGES ON aula6exer4evolucao2.* TO 'administrador' WITH GRANT OPTION;

GRANT 'administrador' TO 'addbd';
GRANT 'administrador' TO 'superr';

CREATE ROLE 'funcionario';

CREATE USER 'jose' IDENTIFIED BY 'usu123';
CREATE USER 'anaM' IDENTIFIED BY 'mana2023';

GRANT SELECT ON aula6exer4evolucao2.* TO 'funcionario';
GRANT INSERT ON aula6exer4evolucao2.DEPENDENTE TO 'funcionario';

GRANT 'funcionario' TO 'jose'@'%';
GRANT 'funcionario' TO 'anaM'@'%';

FLUSH PRIVILEGES;
