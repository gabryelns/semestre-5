-- -------- < Exercício 6 da Aula 4 > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 01/05/2024
-- Autor(es) ..............: Gabryel Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: Exercicio6daAula 4
--
-- 
-- Ultimas Alteracoes
--   01/05/2024 => Criacao da tabela
--
-- ---------------------------------------------------------
CREATE TABLE PROPRIETARIO (
    cpf VARCHAR(11) PRIMARY KEY,
    nome VARCHAR(100),
    endereco VARCHAR(255),
    bairro VARCHAR(100),
    cidade VARCHAR(100),
    estado CHAR(2),
    telefone VARCHAR(20),
    sexo CHAR(1),
    dataNascimento DATE,
    idade INT
);

CREATE TABLE MODELO (
    codigoModelo INT PRIMARY KEY,
    descricaoModelo VARCHAR(255)
);

CREATE TABLE CATEGORIA (
    codigoCategoria INT PRIMARY KEY,
    descricaoCategoria VARCHAR(100)
);

CREATE TABLE VEICULO (
    placa VARCHAR(10) PRIMARY KEY,
    chassi VARCHAR(17),
    cor VARCHAR(50),
    anoFabricacao YEAR,
    cpfProprietario VARCHAR(11),
    codigoModelo INT,
    codigoCategoria INT,
    FOREIGN KEY (cpfProprietario) REFERENCES Proprietario(cpf),
    FOREIGN KEY (codigoModelo) REFERENCES Modelo(codigoModelo),
    FOREIGN KEY (codigoCategoria) REFERENCES Categoria(codigoCategoria)
);

CREATE TABLE TIPOINFRACAO (
    codigoTipoInfracao INT PRIMARY KEY,
    descricaoTipoInfracao VARCHAR(255),
    valorInfracao DECIMAL(10, 2)
);

CREATE TABLE LOCAL_ (
    codigoLocal INT PRIMARY KEY,
    latitude DECIMAL(10, 8),
    longitude DECIMAL(11, 8),
    velocidadePermitida INT
);

CREATE TABLE AGENTE (
    matriculaAgente VARCHAR(20) PRIMARY KEY,
    nomeAgente VARCHAR(100),
    dataContratacao DATE,
    tempoServicoMeses INT
);

CREATE TABLE INFRACAO (
    idInfracao INT PRIMARY KEY,
    veiculoInfrator VARCHAR(17),
    dataHora DATETIME,
    tipoInfracao INT,
    localInfracao INT,
    velocidadeAferida INT,
    matriculaAgente VARCHAR(20),
    FOREIGN KEY (veiculoInfrator) REFERENCES Veiculo(placa),
    FOREIGN KEY (tipoInfracao) REFERENCES TipoInfracao(codigoTipoInfracao),
    FOREIGN KEY (localInfracao) REFERENCES Local(codigoLocal),
    FOREIGN KEY (matriculaAgente) REFERENCES Agente(matriculaAgente)
);