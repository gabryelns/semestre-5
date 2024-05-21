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
--   16/05/2024 => criacao da base de dados e consultas
--
-- ---------------------------------------------------------

USE aula10extra1;

-- A)
SELECT sigla, nome
  FROM ESTADO
 WHERE sigla = 'SP'
   OR sigla = 'DF';

-- B)
	  SELECT CIDADE.nome, CIDADE.sigla
      FROM CIDADE
INNER JOIN ESTADO ON CIDADE.sigla = ESTADO.sigla
     WHERE CIDADE.sigla = 'RJ'
       OR CIDADE.sigla = 'DF'
       OR CIDADE.sigla = 'GO';

-- C)
SELECT CIDADE.nome, ESTADO.nome AS nome_estado, CIDADE.sigla
FROM ESTADO
INNER JOIN CIDADE ON CIDADE.sigla = ESTADO.sigla
WHERE CIDADE.sigla = (SELECT MIN(sigla) FROM ESTADO);

-- D)
 SELECT ESTADO.nome, CIDADE.nome AS cidade_nome, CIDADE.habitantes
FROM ESTADO
INNER JOIN CIDADE ON ESTADO.sigla = CIDADE.sigla
WHERE ESTADO.sigla = 'GO'
ORDER BY ESTADO.nome ASC, CIDADE.nome DESC;

