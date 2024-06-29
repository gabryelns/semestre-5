USE TF_1F_hugomelo;

INSERT INTO TIPOPRODUTO (idTipoProduto, nome, descricao) VALUES
(1, 'Perfume', 'Fragrâncias diversas'),
(2, 'Creme', 'Cremes hidratantes'),
(3, 'Shampoo', 'Produtos para lavagem de cabelo'),
(4, 'Condicionador', 'Produtos para condicionamento de cabelo'),
(5, 'Batom', 'Produtos para os lábios'),
(6, 'Base', 'Maquiagem para o rosto'),
(7, 'Protetor Solar', 'Produtos para proteção solar'),
(8, 'Loção Corporal', 'Hidratantes para o corpo'),
(9, 'Sérum', 'Tratamentos faciais'),
(10, 'Máscara', 'Máscaras faciais e capilares');

INSERT INTO TIPOPAGAMENTO (idPagamento, forma) VALUES
(1, 'Dinheiro'),
(2, 'Cartão de Crédito'),
(3, 'Cartão de Débito'),
(4, 'Pix'),
(5, 'Boleto Bancário');

INSERT INTO MARCA (idMarca, nome) VALUES
(1, 'Natura'),
(2, 'O Boticário'),
(3, 'Eudora'),
(4, 'Avon'),
(5, 'Mary Kay'),
(6, 'Jequiti'),
(7, 'Vult'),
(8, 'Dailus'),
(9, 'L\'Occitane'),
(10, 'The Body Shop');

INSERT INTO CLIENTE (cidade, bairro, logradouro, complemento, nome, idCliente) VALUES
('Brasília', 'Asa Sul', 'Rua 1', 'Apt 101', 'Ana Silva', 1),
('Brasília', 'Asa Norte', 'Rua 2', 'Apt 202', 'Bruna Oliveira', 2),
('Brasília', 'Lago Sul', 'Rua 3', 'Casa 15', 'Carla Souza', 3),
('Brasília', 'Lago Norte', 'Rua 4', 'Casa 20', 'Daniela Lima', 4),
('Brasília', 'Taguatinga', 'Rua 5', 'Apt 303', 'Eduarda Costa', 5),
('Brasília', 'Ceilândia', 'Rua 6', 'Casa 10', 'Fernanda Alves', 6),
('Brasília', 'Guará', 'Rua 7', 'Apt 404', 'Gabriela Santos', 7),
('Brasília', 'Sudoeste', 'Rua 8', 'Apt 505', 'Helena Ribeiro', 8),
('Brasília', 'Águas Claras', 'Rua 9', 'Casa 25', 'Isabela Ferreira', 9),
('Brasília', 'Samambaia', 'Rua 10', 'Casa 30', 'Juliana Martins', 10);

INSERT INTO PRODUTO (idProduto, nome, descricao, idTipoProduto, idMarca) VALUES
(1, 'Essencial', 'Perfume Masculino', 1, 1),
(2, 'Kaiak', 'Perfume Feminino', 1, 1),
(3, 'Cuide-se Bem', 'Creme Hidratante', 2, 2),
(4, 'Lily', 'Perfume Floral', 1, 2),
(5, 'Siàge', 'Shampoo Hidratante', 3, 3),
(6, 'Renew', 'Protetor Solar Facial', 7, 4),
(7, 'Timewise', 'Base Líquida', 6, 5),
(8, 'Amor Amor', 'Perfume Jovem', 1, 6),
(9, 'Aquarela', 'Batom Matte', 5, 7),
(10, 'Hidra+', 'Loção Corporal', 8, 8);

INSERT INTO PEDIDO (idPedido, dataPedido, codigoPedido, valorTaxa) VALUES
(1, '2023-01-10', 'PED001', 15.00),
(2, '2023-02-15', 'PED002', 10.00),
(3, '2023-03-20', 'PED003', 12.50),
(4, '2023-04-25', 'PED004', 20.00),
(5, '2023-05-30', 'PED005', 8.00),
(6, '2023-06-10', 'PED006', 14.00),
(7, '2023-07-15', 'PED007', 17.50),
(8, '2023-08-20', 'PED008', 11.00),
(9, '2023-09-25', 'PED009', 16.00),
(10, '2023-10-30', 'PED010', 18.00);

INSERT INTO COMPRA (idCompra, dataCompra, qtdParcelas, taxaPorcentagem, idCliente, idPagamento) VALUES
(1, '2023-01-15', 2, 0, 1, 1),
(2, '2023-02-20', 1, 0, 2, 2),
(3, '2023-03-25', 3, 0, 3, 3),
(4, '2023-04-30', 1, 0, 4, 4),
(5, '2023-05-05', 2, 0, 5, 5),
(6, '2023-06-10', 1, 0, 6, 1),
(7, '2023-07-15', 3, 0, 7, 2),
(8, '2023-08-20', 1, 0, 8, 3),
(9, '2023-09-25', 2, 0, 9, 4),
(10, '2023-10-30', 1, 0, 10, 5);

INSERT INTO ITEM (validade, idItem, preco, idProduto, idPedido, precoVenda, idCompra) VALUES
('2024-01-10', 1, 150.00, 1, 1, 180.00, 1),
('2024-02-15', 2, 120.00, 2, 2, 150.00, 2),
('2024-03-20', 3, 80.00, 3, 3, 100.00, 3),
('2024-04-25', 4, 200.00, 4, 4, 250.00, 4),
('2024-05-30', 5, 60.00, 5, 5, 75.00, 5),
('2024-06-10', 6, 90.00, 6, 6, 110.00, 6),
('2024-07-15', 7, 110.00, 7, 7, 130.00, 7),
('2024-08-20', 8, 130.00, 8, 8, 160.00, 8),
('2024-09-25', 9, 50.00, 9, 9, 65.00, 9),
('2024-10-30', 10, 70.00, 10, 10, 90.00, 10);

INSERT INTO telefone (idCliente, ddd, numero) VALUES
(1, 61, 999999999),
(2, 61, 988888888),
(3, 61, 977777777),
(4, 61, 966666666),
(5, 61, 955555555),
(6, 61, 944444444),
(7, 61, 933333333),
(8, 61, 922222222),
(9, 61, 911111111),
(10, 61, 900000000);