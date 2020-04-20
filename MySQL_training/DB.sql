CREATE DATABASE website;
USE website;

CREATE TABLE users (user_id INT PRIMARY KEY, first_name VARCHAR(50), last_name VARCHAR(50), email VARCHAR(255));
INSERT INTO users (user_id, first_name, last_name, email) VALUES (1, 'Jacob', 'Hill', 'j.hill@gmail.com');
INSERT INTO users (user_id, first_name, last_name, email) VALUES (2, 'Benjamin', 'Martin', 'b.martin@gmail.com');
INSERT INTO users (user_id, first_name, last_name, email) VALUES (3, 'Emma', 'Carter', 'emma.carter@yahoo.com');
INSERT INTO users (user_id, first_name, last_name, email) VALUES (4, 'Sophia', 'Evans', 'sophia.evans@outlook.com');
INSERT INTO users (user_id, first_name, last_name, email) VALUES (5, 'Lucas', 'Taylor', 'lucas.taylor@yahoo.com');

CREATE TABLE comments (user_id INT, comment_id INT PRIMARY KEY, comment_date DATE, comment_text TEXT, comment_status VARCHAR(50));
INSERT INTO comments (user_id, comment_id, comment_date, comment_text, comment_status) VALUES (20, 1, '2033-01-01', 'Some text', 'spam');
INSERT INTO comments (user_id, comment_id, comment_date, comment_text, comment_status) VALUES (2, 2, '2033-02-02', 'Some text', 'unapproved');
INSERT INTO comments (user_id, comment_id, comment_date, comment_text, comment_status) VALUES (5, 3, '2033-04-05', 'Some text', 'unapproved');
INSERT INTO comments (user_id, comment_id, comment_date, comment_text, comment_status) VALUES (2, 4, '2033-08-15', 'Some text', 'approved');
INSERT INTO comments (user_id, comment_id, comment_date, comment_text, comment_status) VALUES (4, 5, '2033-11-10', 'Some text', 'approved');