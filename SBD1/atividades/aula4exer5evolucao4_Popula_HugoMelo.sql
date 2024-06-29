-- -------- < aula4exer5Evolucao4 > --------
--
--                    SCRIPT DE POPULA (DML)
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
--   29/06/2024 => Adição de tuplas em todas as tabelas
-- ---------------------------------------------------------

USE aula4exer5evolucao4;

INSERT INTO MEDICAMENTO (idMedicamento, nomeMedicamento) VALUES 
(1, 'Paracetamol'),
(2, 'Ibuprofeno'),
(3, 'Dipirona'),
(4, 'Amoxicilina'),
(5, 'Omeprazol'),
(6, 'Captopril'),
(7, 'Losartana'),
(8, 'Metformina'),
(9, 'Simvastatina'),
(10, 'Aspirina');

INSERT INTO PACIENTE (idPaciente, nomeCompleto, cidade, estado, complemento, cep, rua, numeroEndereco, dtNascimento, sexo) VALUES
(1, 'João Silva', 'São Paulo', 'SP', 'Apto 101', 12345678, 'Rua A', 100, '1980-01-01', 'M'),
(2, 'Maria Oliveira', 'Rio de Janeiro', 'RJ', 'Casa', 23456789, 'Rua B', 101, '1985-02-02', 'F'),
(3, 'Carlos Souza', 'Belo Horizonte', 'MG', 'Bloco 2', 34567890, 'Rua C', 102, '1990-03-03', 'M'),
(4, 'Ana Lima', 'Porto Alegre', 'RS', 'Apto 202', 45678901, 'Rua D', 103, '1975-04-04', 'F'),
(5, 'Paula Mendes', 'Curitiba', 'PR', 'Casa', 56789012, 'Rua E', 104, '2000-05-05', 'F'),
(6, 'Rafael Cardoso', 'Recife', 'PE', 'Bloco 3', 67890123, 'Rua F', 105, '1995-06-06', 'M'),
(7, 'Fernanda Rocha', 'Salvador', 'BA', 'Apto 303', 78901234, 'Rua G', 106, '1988-07-07', 'F'),
(8, 'Bruno Santos', 'Fortaleza', 'CE', 'Casa', 89012345, 'Rua H', 107, '1992-08-08', 'M'),
(9, 'Juliana Alves', 'Manaus', 'AM', 'Bloco 4', 90123456, 'Rua I', 108, '1983-09-09', 'F'),
(10, 'Rodrigo Silva', 'Brasília', 'DF', 'Apto 404', 12312312, 'Rua J', 109, '1979-10-10', 'M');

INSERT INTO ESPECIALIDADE (idEspecialidade, nomeEspecialidade) VALUES 
(1, 'Cardiologia'),
(2, 'Neurologia'),
(3, 'Ortopedia'),
(4, 'Pediatria'),
(5, 'Ginecologia'),
(6, 'Dermatologia'),
(7, 'Psiquiatria'),
(8, 'Endocrinologia'),
(9, 'Gastroenterologia'),
(10, 'Oftalmologia');

INSERT INTO MEDICO (numero, uf, nomeCompleto, idEspecialidade) VALUES 
(100001, 'SP', 'Dr. João Cardoso', 1),
(100002, 'RJ', 'Dr. Maria Albuquerque', 2),
(100003, 'MG', 'Dr. Carlos Mendes', 3),
(100004, 'PR', 'Dr. Ana Lima', 4),
(100005, 'RS', 'Dr. José Santana', 5),
(100006, 'BA', 'Dr. Mariana Nunes', 6),
(100007, 'CE', 'Dr. Pedro Rocha', 7),
(100008, 'DF', 'Dr. Luciana Silva', 8),
(100009, 'AM', 'Dr. Ricardo Costa', 9),
(100010, 'PE', 'Dr. Patrícia Souza', 10);

INSERT INTO CONSULTA (idConsulta, dtHora, numero, uf, idPaciente) VALUES 
(1, '2024-06-29 10:00:00', 100001, 'SP', 1),
(2, '2024-06-29 11:00:00', 100002, 'RJ', 2),
(3, '2024-06-29 12:00:00', 100003, 'MG', 3),
(4, '2024-06-29 13:00:00', 100004, 'PR', 4),
(5, '2024-06-29 14:00:00', 100005, 'RS', 5),
(6, '2024-06-29 15:00:00', 100006, 'BA', 6),
(7, '2024-06-29 16:00:00', 100007, 'CE', 7),
(8, '2024-06-29 17:00:00', 100008, 'DF', 8),
(9, '2024-06-29 18:00:00', 100009, 'AM', 9),
(10, '2024-06-29 19:00:00', 100010, 'PE', 10);

INSERT INTO RECEITA (idReceita, descricao, dataEmissao, idConsulta) VALUES 
(1, 'Tomar 1 comprimido de Paracetamol a cada 8 horas', '2024-06-29', 1),
(2, 'Tomar 1 comprimido de Ibuprofeno a cada 6 horas', '2024-06-29', 2),
(3, 'Tomar 1 comprimido de Dipirona a cada 8 horas', '2024-06-29', 3),
(4, 'Tomar 1 comprimido de Amoxicilina a cada 12 horas', '2024-06-29', 4),
(5, 'Tomar 1 comprimido de Omeprazol em jejum', '2024-06-29', 5),
(6, 'Tomar 1 comprimido de Captopril a cada 12 horas', '2024-06-29', 6),
(7, 'Tomar 1 comprimido de Losartana a cada 24 horas', '2024-06-29', 7),
(8, 'Tomar 1 comprimido de Metformina após as refeições', '2024-06-29', 8),
(9, 'Tomar 1 comprimido de Simvastatina à noite', '2024-06-29', 9),
(10, 'Tomar 1 comprimido de Aspirina a cada 4 horas', '2024-06-29', 10);

INSERT INTO telefone (idPaciente, telefone) VALUES
(1, 987654321),
(2, 987654322),
(3, 987654323),
(4, 987654324),
(5, 987654325),
(6, 987654326),
(7, 987654327),
(8, 987654328),
(9, 987654329),
(10, 987654330);


INSERT INTO prescreve (idMedicamento, idReceita) VALUES 
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10);

