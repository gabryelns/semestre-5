-- -------- < aula4exer6 - Evolução 2 > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 01/05/2024
-- Autor(es) ..............: Larissa de Jesus Vieira e Gabryl Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer6Evolucao2
--
-- PROJETO => 01 Base de Dados
--         => 09 Tabelas
--         => 00 Visoes
--         => 00 Perfis (role)
--         => 00 Usuarios
--         => 00 Sequencias
--         => 00 Triggers
--         => 00 Procedimentos
--         => 00 Funcoes

-- 
-- Ultimas Alteracoes
--   06/05/2024 => criar a deleção de todas as tabelas e alterar nome base de dados
-- ---------------------------------------------------------
DELETE FROM INFRACAO WHERE dtHora = '2024-05-01 10:30:00' AND placa = 'ABC1234';
DELETE FROM INFRACAO WHERE dtHora = '2024-05-02 14:45:00' AND placa = 'DEF5678';
DELETE FROM INFRACAO WHERE dtHora = '2024-05-03 08:20:00' AND placa = 'GHI9012';

DELETE FROM VEICULO WHERE placa = 'ABC1234';
DELETE FROM VEICULO WHERE placa = 'DEF5678';
DELETE FROM VEICULO WHERE placa = 'GHI9012';

DELETE FROM PROPRIETARIO WHERE cpfProprietario = '12345678901';
DELETE FROM PROPRIETARIO WHERE cpfProprietario = '23456789012';
DELETE FROM PROPRIETARIO WHERE cpfProprietario = '34567890123';

DELETE FROM telefone WHERE cpfProprietario = '12345678901';
DELETE FROM telefone WHERE cpfProprietario = '23456789012';
DELETE FROM telefone WHERE cpfProprietario = '34567890123';

DELETE FROM AGENTE WHERE matriculaAgente = 10001;
DELETE FROM AGENTE WHERE matriculaAgente = 10002;
DELETE FROM AGENTE WHERE matriculaAgente = 10003;

DELETE FROM LOCAL WHERE codLocal = 1001;
DELETE FROM LOCAL WHERE codLocal = 1002;
DELETE FROM LOCAL WHERE codLocal = 1003;

DELETE FROM TIPOINFRACAO WHERE codInfracao = 1001;
DELETE FROM TIPOINFRACAO WHERE codInfracao = 1002;
DELETE FROM TIPOINFRACAO WHERE codInfracao = 1003;

DELETE FROM MODELO WHERE codModelo = 101;
DELETE FROM MODELO WHERE codModelo = 102;
DELETE FROM MODELO WHERE codModelo = 103;

DELETE FROM CATEGORIA WHERE codCategoria = 1;
DELETE FROM CATEGORIA WHERE codCategoria = 2;
DELETE FROM CATEGORIA WHERE codCategoria = 3;

DROP TABLE INFRACAO;
DROP TABLE VEICULO;
DROP TABLE PROPRIETARIO;
DROP TABLE telefone;
DROP TABLE AGENTE;
DROP TABLE LOCAL;
DROP TABLE TIPOINFRACAO;
DROP TABLE MODELO;
DROP TABLE CATEGORIA;
