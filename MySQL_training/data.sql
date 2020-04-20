USE store;
INSERT INTO vegetables (name, weight, price) VALUES ('Lettuce', 100, 1.65);
INSERT INTO vegetables (name, weight, price) VALUES ('Carrot', 350, 1.9);
INSERT INTO vegetables (name, weight, price) VALUES ('Pumpkin', 700, 2.5);
SELECT * FROM vegetables WHERE price BETWEEN 2 AND 3;
SELECT * FROM vegetables WHERE weight < 400;
SELECT * FROM vegetables WHERE name LIKE '%o' ORDER BY name DESC;