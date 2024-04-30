-- -------- < AULA 4 EXER 5 EVOLUCAO 3 > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 29/04/2024
-- Autor(es) ..............: Gabryel Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: bdFinanceiro
--
-- PROJETO => 01 Base de Dados
--         => 1 Tabela
-- 
-- Ultimas Alteracoes
--   29/04/2024 => criacao do primeiro projeto.
--            
--
-- ---------------------------------------------------------
create table database cadastrar
default character set utf8
default collate utf8_general_ci;

create table 'paciente' (
  'idPaciente' id not null auto_increment,
  'nomeCompleto' varchar(30) not null,
  'dtNascimento' date,
  'sexo' varchar(10),
  'telefone' int,
  'endereco',
  primary key (id) 
) default charset = utf8;