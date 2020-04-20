USE website;
CREATE TABLE customers (
    first_name VARCHAR(255),
    last_name VARCHAR(255),
    address VARCHAR(255),
    country VARCHAR(255),
    password VARCHAR(255)
);

INSERT INTO customers (first_name, last_name, address, country, password)
    VALUES ('Liam', 'Davis', '936 Andover Dr. Brooklyn, NY 112119', 'USA', '12345');
INSERT INTO customers (first_name, last_name, address, country, password)
    VALUES ('Lucas', 'King', '8873 Sage Ave. Cold Lake, AB T9M 0T7', 'Canada', '    qwer');
INSERT INTO customers (first_name, last_name, address, country, password)
    VALUES ('Ethan', 'Miller', '709 Ramblewood St. Hampton, VA 23666', 'USA', '98');