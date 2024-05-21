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
--   16/05/2024 => criacao da base de dados e tabelas
--
-- ---------------------------------------------------------

-- BASE DE DADOS
CREATE DATABASE
  IF NOT EXISTS aula10extra1;

USE aula10extra1;

CREATE TABLE ESTADO(
sigla VARCHAR(2) NOT NULL,
nome VARCHAR(20) NOT NULL,
   
CONSTRAINT ESTADO_PK UNIQUE (sigla)
)ENGINE = InnoDB;

CREATE TABLE CIDADE(
codigo INT NOT NULL,
nome VARCHAR(50) NOT NULL,
sigla VARCHAR(2) NOT NULL,
habitantes BIGINT NOT NULL,
   
CONSTRAINT CIDADE_PK PRIMARY KEY (codigo),
    CONSTRAINT CIDADE_UK UNIQUE (sigla, nome),
    CONSTRAINT CIDADE_FK FOREIGN KEY (sigla) REFERENCES ESTADO (sigla)

)ENGINE = InnoDB;