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
--   06/05/2024 => correção da tabela e alterar nome base de dados
-- ---------------------------------------------------------
create database Detran;

create table PROPRIETARIO (
    cpfProprietario         bigint(12)    primary key,
    nomeProprietario        varchar(60)   NOT NULL,
    bairro                  varchar(20)   NOT NULL,
    cidade                  varchar(20)   NOT NULL,
    estado                  varchar(2)    NOT NULL,
    cep                     bigint(9)     NOT NULL,
    sexo                    enum('M','F') NOT NULL,
    dtNascimento            date          NOT NULL
);

create table TELEFONE (
    idTelefone              bigint(12)    primary key auto_increment,
    cpfProprietario         bigint(12)    NOT NULL,
    telefone                varchar(15)   NOT NULL,
    constraint telefone_FK foreign key (cpfProprietario) references PROPRIETARIO(cpfProprietario)
);

create table VEICULO (
    cpfProprietario         bigint(12)    primary key,
    placa                   varchar(8)    NOT NULL,
    chassi                  varchar(18)   NOT NULL,
    corPredominante         varchar(15)   NOT NULL,
    anoFabricacao           int(5)        NOT NULL,
    codModelo               int(6)        NOT NULL,
    codCategoria            int(2)        NOT NULL,
    constraint VEICULO_FK1 foreign key (codModelo) references MODELO(codModelo),
    constraint VEICULO_FK2 foreign key (codCategoria) references CATEGORIA(codCategoria),
    constraint VEICULO_FK3 foreign key (cpfProprietario) references PROPRIETARIO(cpfProprietario)
);

create table CATEGORIA (
    codCategoria            int(2)        primary key auto_increment,
    nomeCategoria           varchar(20)   NOT NULL
);

create table MODELO (
    codModelo               int(6)        primary key auto_increment,
    nomeModelo              varchar(20)   NOT NULL
);

create table INFRACAO (
    dtHora                  datetime      NOT NULL,
    placa                   varchar(8)    NOT NULL,
    velocidadeAferida       int(3),
    codInfracao             int(4)        NOT NULL,
    codLocal                int(6)        NOT NULL,
    matriculaAgente         int(6)        NOT NULL,
    primary key (dtHora, placa),
    constraint INFRACAO_FK1 foreign key (codInfracao) references TIPOINFRACAO(codInfracao),
    constraint INFRACAO_FK2 foreign key (codLocal) references LOCAL(codLocal),
    constraint INFRACAO_FK3 foreign key (matriculaAgente) references AGENTE(matriculaAgente),
    constraint INFRACAO_FK4 foreign key (placa) references VEICULO(placa)
);

create table TIPOINFRACAO (
    codInfracao             int(4)        primary key auto_increment,
    descricaoInfracao       varchar(100)  NOT NULL,
    valorMulta              decimal(8,2)  NOT NULL
);

create table LOCAL (
    codLocal                int(6)        primary key auto_increment,
    latitude                int(2)        NOT NULL,
    longitude               int(2)        NOT NULL,
    velocidadePermitida     int(3)        NOT NULL
);

create table AGENTE (
    matriculaAgente         int(6)        primary key auto_increment,
    nomeAgente              varchar(60)   NOT NULL,
    dtContratacao           date          NOT NULL
);

