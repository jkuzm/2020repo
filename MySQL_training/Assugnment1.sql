#CREATE DATABASE store;
use store;
#CREATE TABLE vegetables1(name VARCHAR(50), weight INT, price DOUBLE);

#INSERT INTO vegetables1 (name,weight,price) VALUES ('Onion',200,1.93);
#INSERT INTO vegetables1 (name,weight,price) VALUES ('Potato',1000,2.4),('Tomato',400,3.95);
#insert into vegetables1 (name,Weight,Price) 
#	values ('Lettuce',100,1.65),('Carrot',350,1.9),('Pumpkin',700,2.5);
#select * from vegetables where price between 2 and 3;
#select * from vegetables where Weight < 400;
#name ends with letter 'o', in descending order
#select * from vegetables1 where name like '%o' order by name desc;
#28.assignment3
#select count(*) from vegetables where weight >= 350;
#select avg(Price) from vegetables;
#select min(price),max(price) from vegetables;
#delete heaviest vegetable
#delete from vegetables order by weight desc limit 1;
#SELECT * FROM vegetables;
#show tables;
#drop table vegetables,vegetables1;
#show tables;
#add a column
#alter table vegetables add column price_category varchar(50);
#if price >2 set category to expensive
#update vegetables set price_category='expensive' where price >2;
#update vegetables set price_category='cheap' where price <=2;
#show how many cheap and how many expensive
#select count(*) from vegetables where price_category='expensive';
#select price_category, count(*) from vegetables where price_category='cheap';
#to show both categories:
#select price_category,count(*) from vegetables group by price_category;
#drop table vegetables;
show tables;
