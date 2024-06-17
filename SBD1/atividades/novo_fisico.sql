-- -------- < cosmeticos > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 16/05/2024
-- Autor(es) ..............: Hugo Queiroz Camelo de Melo,
-- ........................: GabryeL Nícolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: cosmeticos
--
-- PROJETO => 01 Base de Dados
--         => 07 Tabelas
--
-- Ultimas Alteracoes
--   
--
-- ---------------------------------------------------------

-- BASE DE DADOS
CREATE DATABASE
  IF NOT EXISTS cosmeticos;

USE cosmeticos;

CREATE TABLE MARCA (
    idMarca INT NOT NULL,
    nome VARCHAR(30) NOT NULL,
    CONSTRAINT MARCA_PK PRIMARY KEY (idMarca)
) ENGINE = InnoDB;

CREATE TABLE PRODUTO (
    codigoProduto INT NOT NULL,
    idMarca INT NOT NULL,
    nome VARCHAR(45) NOT NULL,
    descricao VARCHAR(100) NOT NULL,
    CONSTRAINT PRODUTO_PK PRIMARY KEY (codigoProduto),
    CONSTRAINT PRODUTO_FK FOREIGN KEY (idMarca) REFERENCES MARCA (idMarca)
) ENGINE = InnoDB;

CREATE TABLE CLIENTE (
    idCliente INT NOT NULL,
    nomeCompleto VARCHAR(30) NOT NULL,
    logradouro VARCHAR(50),
    cep VARCHAR(8),
    cidade VARCHAR(30),
    CONSTRAINT CLIENTE_PK PRIMARY KEY (idCliente)
) ENGINE = InnoDB;

CREATE TABLE TELEFONE (
    idCliente INT NOT NULL,
    telefone DECIMAL(11) NOT NULL,
    CONSTRAINT TELEFONE_UK UNIQUE (idCliente, telefone),
    CONSTRAINT TELEFONE_CLIENTE_FK FOREIGN KEY (idCliente) REFERENCES CLIENTE (idCliente)
) ENGINE = InnoDB;

CREATE TABLE LOTE (
    codigoProduto INT NOT NULL,
    unidades INT NOT NULL,
    precoCompra DECIMAL(6,2) NOT NULL,
    dataCompra DATE NOT NULL,
    validade DATE,
    CONSTRAINT LOTE_PK PRIMARY KEY (dataCompra, codigoProduto),
    CONSTRAINT LOTE_FK FOREIGN KEY (codigoProduto) REFERENCES PRODUTO (codigoProduto)
) ENGINE = InnoDB;

CREATE TABLE TIPOPAGAMENTO (
    idTipo INT NOT NULL,
    tipo VARCHAR(50) NOT NULL,
    CONSTRAINT TIPOPAGAMENTO_PK PRIMARY KEY (idTipo)
) ENGINE = InnoDB;

CREATE TABLE PEDIDO (
    idPedido INT NOT NULL,
    idCliente INT NOT NULL,
    dataVenda DATE NOT NULL,
    precoVenda DECIMAL NOT NULL,
    precoCompra DECIMAL(6,2) NOT NULL,
    idTipo INT NOT NULL,
    CONSTRAINT PEDIDO_PK PRIMARY KEY (idPedido),
    CONSTRAINT PEDIDO_CLIENTE_FK FOREIGN KEY (idCliente) REFERENCES CLIENTE (idCliente),
    CONSTRAINT PEDIDO_TIPOPAGAMENTO_FK FOREIGN KEY (idTipo) REFERENCES TIPOPAGAMENTO (idTipo)
) ENGINE = InnoDB;

CREATE TABLE POSSUI (
    idPedido INT NOT NULL,
    codigoProduto INT NOT NULL,
    CONSTRAINT POSSUI_PK PRIMARY KEY (idPedido, codigoProduto),
    CONSTRAINT POSSUI_PEDIDO_FK FOREIGN KEY (idPedido) REFERENCES PEDIDO (idPedido),
    CONSTRAINT POSSUI_PRODUTO_FK FOREIGN KEY (codigoProduto) REFERENCES PRODUTO (codigoProduto)
) ENGINE = InnoDB;
