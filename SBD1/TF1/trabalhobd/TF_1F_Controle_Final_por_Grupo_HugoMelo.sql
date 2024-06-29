USE TF_1F_hugomelo;

CREATE ROLE 'revendedor', 'administrador';
GRANT SELECT, INSERT ON TF_1F_hugomelo.* TO 'revendedor';
GRANT ALL PRIVILEGES ON TF_1F_hugomelo.* TO 'administrador';

CREATE USER 'leticia'
	IDENTIFIED BY 'password123';
GRANT 'revendedor' TO 'leticia'
	WITH ADMIN OPTION;
    
CREATE USER 'joao'
	IDENTIFIED BY 'joao12';
GRANT 'revendedor' TO 'joao';

CREATE USER 'maria'
	IDENTIFIED BY 'devpassion';
GRANT 'administrador' TO 'maria';

CREATE USER 'lucas'
	IDENTIFIED BY 'senhadific123';
GRANT 'revendedor' TO 'lucas';
