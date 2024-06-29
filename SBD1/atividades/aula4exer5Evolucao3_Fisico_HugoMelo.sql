-- -------- < aula4exer5Evolucao4 > --------
--
--                    SCRIPT DE CRIACAO (DDL)
--
-- Data Criacao ...........: 28/06/2024
-- Autor(es) ..............: Hugo Queiroz Camelo de Melo,
-- ........................: GabryeL Nícolas Soares de Sousa,
-- ........................: Caio Felipe Rocha Rodrigues,
-- ........................: Danilo Cesar Tertuliano Melo
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer5Evolucao4
--
-- PROJETO => 01 Base de Dados
--         => 08 Tabelas
--         => 02 Perfis (role)
--         => 04 Usuarios
--
-- Ultimas Alteracoes
--   29/06/2024 => Adição de if not exists na criação da base de dados
--   29/06/2024 => Adição de ENGINE = InnoDB em todas as tabelas
--   29/06/2024 => CORRIGE ERROS
-- ---------------------------------------------------------
CREATE DATABASE
	if not exists aula4exer5evolucao4;
    
USE aula4exer5evolucao4;

CREATE TABLE MEDICAMENTO (
    nomeMedicamento VARCHAR(100),
    idMedicamento DECIMAL(9),
    CONSTRAINT MEDICAMENTO_PK PRIMARY KEY (idMedicamento)
)ENGINE = InnoDB;

CREATE TABLE PACIENTE (
    idPaciente DECIMAL(9),
    nomeCompleto VARCHAR(60),
    cidade VARCHAR(30),
    estado VARCHAR(2),
    complemento VARCHAR(100),
    cep DECIMAL(8),
    rua VARCHAR(30),
    numeroEndereco DECIMAL(3),
    dtNascimento DATE,
    sexo CHAR(1),
    CONSTRAINT PACIENTE_PK PRIMARY KEY (idPaciente)
)ENGINE = InnoDB;

CREATE TABLE ESPECIALIDADE (
    nomeEspecialidade VARCHAR(30),
    idEspecialidade DECIMAL(9),
    CONSTRAINT ESPECIALIDADE_PK PRIMARY KEY (idEspecialidade)
)ENGINE = InnoDB;

CREATE TABLE MEDICO (
    nomeCompleto VARCHAR(60),
    numero DECIMAL(6),
    uf VARCHAR(2),
    idEspecialidade DECIMAL(9),
    CONSTRAINT MEDICO_PK PRIMARY KEY (numero, uf),
    CONSTRAINT FK_MEDICO_ESPECIALIDADE FOREIGN KEY (idEspecialidade) REFERENCES ESPECIALIDADE (idEspecialidade)
)ENGINE = InnoDB;

CREATE TABLE CONSULTA (
    dtHora TIMESTAMP,
    idConsulta DECIMAL(9),
    numero DECIMAL(6),
    uf VARCHAR(2),
    idPaciente DECIMAL(9),
    CONSTRAINT CONSULTA_PK PRIMARY KEY (idConsulta),
    CONSTRAINT FK_CONSULTA_MEDICO FOREIGN KEY (numero, uf) REFERENCES MEDICO (numero, uf),
    CONSTRAINT FK_CONSULTA_PACIENTE FOREIGN KEY (idPaciente) REFERENCES PACIENTE (idPaciente)
)ENGINE = InnoDB;

CREATE TABLE RECEITA (
    idReceita DECIMAL(9),
    descricao VARCHAR(100),
    dataEmissao DATE,
    idConsulta DECIMAL(9),
    CONSTRAINT RECEITA_PK PRIMARY KEY (idReceita),
    CONSTRAINT FK_RECEITA_CONSULTA FOREIGN KEY (idConsulta) REFERENCES CONSULTA (idConsulta) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE telefone (
    idPaciente DECIMAL(9) NOT NULL,
    telefone DECIMAL(9),
    CONSTRAINT TELEFONE_UK UNIQUE (idPaciente, telefone),
    CONSTRAINT FK_TELEFONE_PACIENTE FOREIGN KEY (idPaciente) REFERENCES PACIENTE (idPaciente)
)ENGINE = InnoDB;

CREATE TABLE prescreve (
    idMedicamento DECIMAL(9),
    idReceita DECIMAL(9),
    CONSTRAINT FK_PRESCREVE_MEDICAMENTO FOREIGN KEY (idMedicamento) REFERENCES MEDICAMENTO (idMedicamento) ON DELETE RESTRICT,
    CONSTRAINT FK_PRESCREVE_RECEITA FOREIGN KEY (idReceita) REFERENCES RECEITA (idReceita) ON DELETE SET NULL
)ENGINE = InnoDB;
