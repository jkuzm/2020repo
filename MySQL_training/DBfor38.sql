CREATE DATABASE store;
USE store;

CREATE TABLE brands (id INT, name VARCHAR(255), country VARCHAR(50), founded INT);

INSERT INTO brands (id, name, country, founded) VALUES (1, 'Nike', 'USA', 1964);
INSERT INTO brands (id, name, country, founded) VALUES (2, 'Adidas', 'Germany', 1924);
INSERT INTO brands (id, name, country, founded) VALUES (3, 'New Balance', 'USA', 1906);
INSERT INTO brands (id, name, country, founded) VALUES (4, 'ASICS', 'Japan', 1949);
INSERT INTO brands (id, name, country, founded) VALUES (5, 'Skechers', 'USA', 1992);
INSERT INTO brands (id, name, country, founded) VALUES (6, 'Fila', 'South Korea', 1911);

CREATE TABLE shoes (id INT, brand_id INT, name VARCHAR(255), price DOUBLE, color VARCHAR(100));
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (1, 2, 'Ultraboost 20', 180, 'black');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (2, 3, '574 Core', 80, 'white');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (3, 6, 'Grant Hill 1', 110, 'black');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (4, 2, 'NMD_R1', 130, 'maroon');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (5, 4, 'Gel Kayano 26', 160, 'rose');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (6, 0, 'Super S', 30, 'white');
INSERT INTO shoes (id, brand_id, name, price, color) VALUES (7, 1, 'Air Jordan 1', 160, 'red');
