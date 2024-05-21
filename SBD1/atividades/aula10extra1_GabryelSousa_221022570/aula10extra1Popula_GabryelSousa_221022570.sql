-- -------- < aula10extra1 > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 16/05/2024
-- Autor(es) ..............: Gabryel Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula10extra1
--
-- PROJETO => 01 Base de Dados
--         => 02 Tabelas
--
-- Ultimas Alteracoes
--   16/05/2024 => criacao da base de dados e insere valores
--
-- ---------------------------------------------------------

USE aula10extra1;

INSERT INTO ESTADO VALUES
('RJ', 'RIO DE JANEIRO'),
('SP', 'SAO PAULO'),
('DF', 'DISTRITO FEDERAL'),
('GO', 'GOIAS');

INSERT INTO CIDADE VALUES
( 12345, 'COPACABANA', 'RJ', 4161109164),
( 34567, 'CABO FRIO', 'RJ', 86761109164),
( 45678, 'BRASILIA', 'DF', 67901109164),
( 56789, 'GAMA', 'DF', 567809164),
( 23456, 'GUARULHOS', 'SP', 41667899164),
( 67891, 'PIRAPOZINHO', 'SP', 1610879064),
( 23567, 'GOIANIA', 'GO', 41667899164),
( 78910, 'NOVO GAMA', 'GO', 416134510894);

