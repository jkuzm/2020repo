# CREATE TABLE staff(id INT, first_name varchar(50), last_name varchar(50), email varchar(50));
#INSERT INTO staff(id,first_name,last_name,email) VALUES(1,'James','Davis','j_davis@gmail.com');
#INSERT INTO staff(id,first_name,last_name,email) VALUES(2,'Mary','Johnson','m_johnson@gmail.com');
#SHOW TABLES
#INSERT INTO staff(id,first_name,last_name,email) VALUES(3,'Michael','Smith','m_smith@aol.com');
#multiple rows:
#INSERT INTO staff(id,first_name,last_name,email) VALUES
#(4,'Julia','Kukushkina','heremail@aol.com'), (5,'Ivan','Lapshin','hisem@gmail.com');
#INSERT INTO staff(id,first_name,email) VALUES(6,'Liza','lilili@aol.com');
#SELECT first_name,last_name FROM staff;
#SELECT * FROM staff;
#continued after assignment1
use website;

 
#insert into staff(id, first_name, last_name, email)
#	values(7,'James','Baker','j_b@aol.com');
#select * from staff;
#select first_name from staff;
#select distinct first_name from staff;
#select distinct first_name, last_name from staff;
#select * from staff where first_name='James';
#select * from staff where id>3;
#select * from staff where id <= 3;
#select * from staff where id <> 4; #same as !=
#select * from staff where first_name != 'Mary';
#select * from staff where first_name = 'James';
#select * from staff where id between 2 and 4; #range boundaries included
#select * from staff where first_name in ('James','Mary');
#select * from staff where first_name not in ('James','Mary');
#wildcards: % - zero,one ormultiple chars, _ - just one char
#select * from staff where email like '%gmail.com';
#select *from staff where email not like 'm_%@%.com';
#select * from staff where last_name is not null;
#select * from staff where last_name is null;
#select * from staff order by first_name;
#select * from staff order by last_name;
#select * from staff order by id;
#descending order:
#select * from staff order by last_name desc;
#select * from staff order by id desc;
#select * from staff order by first_name,last_name;
#select * from staff order by last_name,first_name;

#insert into staff (id,first_name,last_name,email) 
#	values(8,'Ashley','Flores','ashley.flores@aol.com');
#set SQL_SAFE_UPDATES=0;
#update staff set email='for.michael@gmail.com' where id=3;
#update staff set last_name='Flores',email='ashley.flores@aol.com' where id=8;
#INSERT INTO staff (id, first_name, last_name, email)
#	VALUES (9, 'Oliver', 'Green', 'oli.green@aol.com');
#INSERT INTO staff (id, first_name, last_name, email)
#	VALUES (10, 'Noah', 'Scott', 'noah888@yahoo.com');
#INSERT INTO staff (id, first_name, last_name, email)
#	VALUES (11, 'Evelyn', 'Adams', 'not_an_email');
#INSERT INTO staff (id, first_name, last_name, email)
#	VALUES (12, 'Aurora', 'Stewart', 'like_email@email');
#delete from staff where id=10;
#delete by wildcard invalid emails
#delete from staff where email not like '%@%.%';
#delete from staff where id=8;

#Basics part 2
#alter table staff add salary double;
#delete from staff where id between 4 and 6;
#
#	(4,'James','Baker','james.baker23@aol.com'), 
#INSERT INTO staff(id,first_name,email) VALUES (6,'Tom','tom_tommy@gmail.com');
#update staff set id=7 where first_name = 'Oliver';
#select * from staff order by id;
#aggregates
#select min(salary) from staff;
#last name in alphabetical order;
#select max(first_name) from staff;
#select sum(salary) from staff;
#select avg(salary) from staff;
#select count(last_name) from staff;
#number of rows
#select count(*) from staff;
#group by
#alter table staff add department varchar(255);
#select * from staff;
#select department, count(department) from staff group by department;
#group by means for each
#select department, min(salary),max(salary),avg(salary),sum(salary)
#	from staff group by department;
#select * from staff where id >=4 and last_name is not null and department like 'Soft%';
#select * from staff where first_name = 'James' or salary > 70000;
#select * from staff where not department = 'Software Development';
#select * from staff where salary >=70000 and (first_name ='James' or first_name ='Ashley');
#select * from staff where first_name in ('James','Tom');
#select department,avg(salary) from staff group by department having avg(salary)>50000;
#after where clause we can't use aggregate, but after having clause we can
#select department,avg(salary) from staff 
#	group by department having avg(salary)>50000 order by department;
#rollup
#select department,sum(salary) from staff 
#	group by department with rollup;
#get first in query - limit 1
#
#select * from staff where department like 'Softw%' 
#	order by salary desc limit 1;
#alter table staff modify department text;
#capitalize department column title name
#alter table staff change department Department text;
#delete column - drop
#alter table staff drop Department;
#delete whole table
#show tables;
#drop table staff;
#drop table vegetables;
#show tables;
#drop database website;
#show databases;






