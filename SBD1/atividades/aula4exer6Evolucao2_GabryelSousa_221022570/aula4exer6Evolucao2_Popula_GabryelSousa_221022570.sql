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
--   06/05/2024 => inserção de dados de todas as tabelas e alterar nome base de dados
-- ---------------------------------------------------------
INSERT INTO PROPRIETARIO (cpfProprietario, nomeProprietario, bairro, cidade, estado, cep, sexo, dtNascimento) 
VALUES 
('12345678901', 'João Silva', 'Centro', 'São Paulo', 'SP', '01000-000', 'M', '1980-01-15'),
('23456789012', 'Maria Santos', 'Jardim', 'Rio de Janeiro', 'RJ', '20000-000', 'F', '1985-05-20'),
('34567890123', 'Carlos Oliveira', 'Boa Vista', 'Belo Horizonte', 'MG', '30000-000', 'M', '1990-09-10');

INSERT INTO TELEFONE (cpfProprietario, telefone) 
VALUES 
('12345678901', '(11) 9999-8888'),
('23456789012', '(21) 98888-7777'),
('34567890123', '(31) 97777-6666');

INSERT INTO CATEGORIA (nomeCategoria) 
VALUES 
('Categoria A'),
('Categoria B'),
('Categoria C');

INSERT INTO MODELO (nomeModelo) 
VALUES 
('Modelo X'),
('Modelo Y'),
('Modelo Z');

INSERT INTO VEICULO (placa, chassi, corPredominante, anoFabricacao, codModelo, codCategoria, cpfProprietario) 
VALUES 
('ABC1234', '123ABC456DEF789', 'Preto', 2020, 1, 1, '12345678901'),
('DEF5678', '456DEF789GHI012', 'Branco', 2018, 2, 2, '23456789012'),
('GHI9012', '789GHI012JKL345', 'Azul', 2019, 3, 3, '34567890123');

INSERT INTO AGENTE (nomeAgente, dtContratacao) 
VALUES 
('Ana Souza', '2020-01-01'),
('Pedro Oliveira', '2019-03-15'),
('Mariana Silva', '2021-05-10');

INSERT INTO LOCAL (latitude, longitude, velocidadePermitida) 
VALUES 
(-23.5505, -46.6333, 60),
(-22.9068, -43.1729, 50),
(-19.9167, -43.9345, 40);

INSERT INTO TIPOINFRACAO (descricaoInfracao, valorMulta) 
VALUES 
('Excesso de velocidade', 200.00),
('Estacionamento irregular', 150.00),
('Dirigir sob efeito de álcool', 500.00);
