
-- -------- < aula4exer6Evolucao3 > --------
--
--                    SCRIPT DE MANIPULAÇÃO (DML)
--
-- Data Criacao ...........: 24/06/2024
-- Autor(es) ..............: Gabryel Nicolas Soares de Sousa
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer6Evolucao3
--
-- PROJETO => 01 Base de Dados
--         => 09 Tabelas
--
-- Ultimas Alteracoes
--   24/06/2024 => criacao das subconsultas exigidas pelo enunciado
-- ---------------------------------------------------------

-- BASE DE DADOS
USE aula4exer6Evolucao3;

-- 1
INSERT INTO telefone (telefone, cpfProprietario)
SELECT 61900000000 + ROW_NUMBER() OVER (ORDER BY cpfProprietario), cpfProprietario
FROM PROPRIETARIO
WHERE cpfProprietario NOT IN (SELECT cpfProprietario FROM telefone);

-- 2
UPDATE VEICULO V
JOIN PROPRIETARIO P ON V.cpfProprietario = P.cpfProprietario
SET V.corPredominante = 'Cinza'
WHERE P.bairro = 'Asa Norte';

-- 3
DELETE FROM INFRACAO
WHERE EXISTS (
    SELECT 1
    FROM LOCALIZACAO L
    WHERE INFRACAO.codLocal = L.codLocal
    AND INFRACAO.velocidadeAferida > L.velocidadePermitida + 20
);

-- 4
SELECT nomeProprietario, cpfProprietario
FROM PROPRIETARIO
WHERE cpfProprietario IN (
    SELECT V.cpfProprietario
    FROM VEICULO V
    INNER JOIN CATEGORIA C ON V.codCategoria = C.codCategoria
    WHERE C.nomeCategoria = 'Automóvel'
);
