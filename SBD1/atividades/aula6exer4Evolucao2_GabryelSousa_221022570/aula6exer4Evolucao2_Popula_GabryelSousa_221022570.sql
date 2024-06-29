-- -------- ula 6 Exercicio 4 evolucao 2 --------
--
--                    SCRIPT DE POPULA (DML)
--
-- Data Criacao ...........: 28/05/2024
-- Autor(es) ..............: Caio Felipe Rocha Rodrigues e Gabryel Nícolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula6exer4evolucao2
--
-- PROJETO => 01 Base de Dados
--         => 05 Tabelas
-- 
-- Ultimas Alteracoes
--   28/05/2024 => Primeira versao BD
--
-- ---------------------------------------------------------

USE aula6exer4evolucao2;

INSERT INTO EMPREGADO(idPessoa, matricula, salario, numero, bairro, rua, idSupervisor, nome, sexo, dataNascimento) VALUES
(1, '22100', 14859.49, '6', 'Taguatinga', 'QSD 15', NULL, 'Caio Felipe Rocha Rodrigues', 'M', '2004-05-03'),
(2, '22101', 1859.38, '7', 'Riacho Fundo', 'Caub I', 1, 'Ana Maria Valadares', 'F', '1999-04-05'),
(3, '22102', 3483.20, '9', 'Riacho Fundo', 'Avenida Sucupira', 1, 'José Ricardo Silva', 'M', '1987-03-12'),
(4, '22103', 1859.38, '11', 'Ponte Alta', 'Av. Buritis', 3, 'João Pereira Fernandes', 'M', '2001-10-09'),
(5, '22104', 2300.75, '12', 'Ceilândia', 'QNM 10', 1, 'Carla Santos Ferreira', 'F', '1995-06-15'),
(6, '22105', 4100.50, '15', 'Asa Sul', 'SQS 308', 2, 'Roberto Carlos Alves', 'M', '1982-12-02');

INSERT INTO DEPARTAMENTO(codigo, nome, idSupervisor, dataAssumiu) VALUES
(101, 'Recursos Humanos', 1, '2021-01-15'),
(102, 'Tecnologia da Informação', 2, '2019-06-30'),
(103, 'Financeiro', 3, '2020-09-10'),
(104, 'Marketing', 4, '2018-11-25'),
(105, 'Pesquisa e Desenvolvimento', 5, '2017-04-20'),
(106, 'Vendas', 6, '2018-02-14');

INSERT INTO DEPENDENTE(idPessoa, nome, sexo, dataNascimento, grauLigacao, idEmpregado) VALUES
(5, 'Maria Fernanda Rocha', 'F', '2020-05-04', 'Filho', 4),
(6, 'João Pedro Silva', 'M', '2018-11-22', 'Filho', 1),
(7, 'Ana Clara Souza', 'F', '2015-07-19', 'Filho', 2),
(8, 'Lucas Matheus Lima', 'M', '2012-03-08', 'Filho', 3),
(9, 'Beatriz Santos Ferreira', 'F', '2016-01-14', 'Filho', 5),
(10, 'Luiz Felipe Alves', 'M', '2010-09-10', 'Filho', 6);

INSERT INTO PROJETO(idProjeto, nome, rua, numero, bairro, idDepartamento) VALUES
(201, 'Implementação ERP', 'Av. das Nações Unidas', '123', 'Centro', 101),
(202, 'Desenvolvimento App Mobile', 'Rua da Consolação', '567', 'Bela Vista', 102),
(203, 'Reestruturação Financeira', 'Av. Paulista', '890', 'Jardins', 103),
(204, 'Campanha Publicitária 2024', 'Rua Oscar Freire', '345', 'Pinheiros', 104),
(205, 'Desenvolvimento de IA', 'Rua Vergueiro', '78', 'Liberdade', 105),
(206, 'Expansão de Mercado', 'Av. Ipiranga', '456', 'República', 106);

INSERT INTO trabalha(idProjeto, idPessoa, horasSemanais) VALUES
(201, 1, 20),
(202, 2, 30),
(203, 3, 25),
(204, 4, 35),
(205, 5, 40),
(206, 6, 15);