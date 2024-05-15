--
-- -------- < aula4exer6Evolucao3 Fisico > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 05/05/2024
-- Autor(es) ..............: Arthur Heleno do Couto da Silva e Gabryel Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer6Evolucao3
--
-- PROJETO => 01 Base de Dados
--         => 11 Tabelas
--
-- 
-- Ultimas Alteracoes
--   06/05/2024 => Adição de if not exists na criação da base de dados
--   06/05/2024 => Adição de ENGINE = InnoDB em todas as tabelas
--   13/05/2024 => CORRIGE ERROS
--
-- ---------------------------------------------------------

-- BASE DE DADOS
CREATE DATABASE 
IF NOT EXISTS aula4exer6Evolucao3;

USE aula4exer6Evolucao3;


-- TABELAS

CREATE TABLE VEICULO (
    placa VARCHAR(8) PRIMARY KEY,
    chassi VARCHAR(18) UNIQUE,
    corPredominante VARCHAR(15),
    modelo VARCHAR(18),
    categoria VARCHAR(18),
    anoDeFabricacao DATETIME,
    codModelo INT(6),
    codCategoria INT(2),
    cpf BIGINT
    CONSTRAINT FK_VEICULO_2 FOREIGN KEY (codModelo) REFERENCES MODELO (codModelo)
    CONSTRAINT FK_VEICULO_3 FOREIGN KEY (codCategoria) REFERENCES CATEGORIA (codCategoria)
    CONSTRAINT FK_VEICULO_4 FOREIGN KEY (cpf) REFERENCES PROPRIETARIO (cpf)
)ENGINE = InnoDB;;

CREATE TABLE PROPRIETARIO (
    cpf BIGINT PRIMARY KEY,
    nome VARCHAR(60),
    logradouro VARCHAR(20),
    numero VARCHAR(20),
    complemento VARCHAR(2),
    bairro BIGINT,
    cidade VARCHAR(18),
    estado VARCHAR(8),
    sexo CHAR('M', 'F'),
    dataDeNascimento DATETIME
    CONSTRAINT FK_PROPRIETARIO_2 FOREIGN KEY (telefone) REFERENCES telefone (telefone)
)ENGINE = InnoDB;;

CREATE TABLE MODELO (
    codModelo INT(6) PRIMARY KEY,
    nomeModelo VARCHAR(20)
)ENGINE = InnoDB;;

CREATE TABLE CATEGORIA (
    codCategoria INT(2) PRIMARY KEY,
    nomeCategoria VARCHAR(20)
)ENGINE = InnoDB;;

CREATE TABLE TIPOINFRACAO (
    codTipoinfracao INT(4) PRIMARY KEY,
    nome VARCHAR(100),
    valorDaMulta FLOAT
)ENGINE = InnoDB;;

CREATE TABLE INFRACAO (
    velocidadeAferida INT(6),
    dataHora DATETIME,
    codTipoinfracao INT(4),
    codLocalizacao INT(6),
    matriculaFuncional BIGINT,
    placa VARCHAR(8),
    PRIMARY KEY (dataHora, placa, codTipoinfracao)
    CONSTRAINT FK_INFRACAO_1 FOREIGN KEY (codTipoinfracao) REFERENCES TIPOINFRACAO (codTipoinfracao)
    CONSTRAINT FK_INFRACAO_2 FOREIGN KEY (codLocalizacao) REFERENCES LOCALIZACAO (codLocalizacao)
    CONSTRAINT FK_INFRACAO_3 FOREIGN KEY (matriculaFuncional) REFERENCES AGENTE (matriculaFuncional)
    CONSTRAINT FK_INFRACAO_4 FOREIGN KEY (placa) REFERENCES VEICULO (placa)
)ENGINE = InnoDB;;

CREATE TABLE LOCALIZACAO (
    codLocalizacao INT(6) PRIMARY KEY,
    latitude INT(6),
    longitude INT(6),
    velocidadePermitida INT(3)
)ENGINE = InnoDB;;

CREATE TABLE AGENTE (
    matriculaFuncional BIGINT PRIMARY KEY,
    nome VARCHAR(60),
    dataDeContratacao DATETIME
)ENGINE = InnoDB;;

CREATE TABLE telefone (
    telefone INT NOT NULL PRIMARY KEY,
    cpf BIGINT
)ENGINE = InnoDB;;

ALTER TABLE VEICULO ADD CONSTRAINT FK_VEICULO_4
    FOREIGN KEY (cpf)
    REFERENCES PROPRIETARIO (cpf)
    ON DELETE RESTRICT;
 
ALTER TABLE PROPRIETARIO ADD CONSTRAINT FK_PROPRIETARIO_2
    FOREIGN KEY (FK_telefone_telefone_PK)
    REFERENCES telefone (telefone)
    ON DELETE NO ACTION;
 
ALTER TABLE INFRACAO ADD CONSTRAINT FK_INFRACAO_1
    FOREIGN KEY (codTipoinfracao)
    REFERENCES TIPOINFRACAO (codTipoinfracao)
    ON DELETE RESTRICT;
 
ALTER TABLE INFRACAO ADD CONSTRAINT FK_INFRACAO_2
    FOREIGN KEY (codLocalizacao)
    REFERENCES LOCALIZACAO (codLocalizacao)
    ON DELETE CASCADE;
 
ALTER TABLE INFRACAO ADD CONSTRAINT FK_INFRACAO_3
    FOREIGN KEY (matriculaFuncional)
    REFERENCES AGENTE (matriculaFuncional)
    ON DELETE CASCADE;
 
ALTER TABLE INFRACAO ADD CONSTRAINT FK_INFRACAO_4
    FOREIGN KEY (placa)
    REFERENCES VEICULO (placa)
    ON DELETE CASCADE;
 
ALTER TABLE INFRACAO ADD CONSTRAINT FK_INFRACAO_5
    FOREIGN KEY (codigoLocal???)
    REFERENCES ??? (???);
 
ALTER TABLE telefone ADD CONSTRAINT FK_telefone_2
    FOREIGN KEY (cpf???)
    REFERENCES ??? (???);