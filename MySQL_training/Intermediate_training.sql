#Intermidiate
#USE WEBSITE;
#select users.first_name,comments.comment_id from users
#	inner join comments on users.user_id=comments.user_id;
#select users.first_name,comments.comment_id from users
#left join comments on users.user_id=comments.user_id order by users.first_name;
#select users.first_name,comments.comment_id from users right join comments
#on users.user_id=comments.user_id;
#cross join
#use cafe;
#show tables;
#select * from coffee;
#select * from syrups;
#select coffee.name,coffee.size,syrups.name from coffee
#cross join syrups;
#aliases
#select coffee.name as coffee,coffee.size,syrups.name as syrup
#from coffee cross join syrups;
#select c.name as coffee,c.size,s.name as syrup
#from coffee as c cross join syrups as s;
#select name,price from  coffee union select name,price from syrups;
#select 'coffee' as type, name, price from coffee union
#select 'syrup', name, price from syrups;
#select * from syrups;
#insert into syrups (syrup_id,name,price) values(4,'Irish Cream',0.5);
#
#union all to show all instead of distinct (non-repeating)
#select price from coffee union all select price from syrups;
#select sum(price) from
#(select price from coffee union all select price from syrups) as prices;

#Intermediate part 2
#constrains
#create table books (name varchar(255) not null, 
#author varchar(255) not null,format varchar(50),
#pages int,id int not null);
#insert into books (name,author,format, pages) values('The Outsider','Stephen King', 'hardcover', 577);
#insert into books (name,author,format, pages) 
#values('Where The Crawdads Sing','Delia Owens','e-book',379);
#select * from books;
#show properties of fields of table:

#change column properties:
#UPDATE books SET id=11 where author like 'Del%'; 
#ALTER TABLE books ADD CONSTRAINT u_id unique (id);
#select * from books;
#drop table books;
#create table books (name varchar(255) not null, 
#author varchar(255) not null,format varchar(50),
#pages int,id int not null unique auto_increment);
#describe books;
#insert into books (name,author,format,pages)
#values('Origin','Dan Brown','hardcover',480);
#select * from books;
#drop table books;
#create table books (name varchar(255) not null, 
#author varchar(255) not null,
#format varchar(50) default 'hardcover',
#pages int check(pages>0),
#id int not null unique auto_increment);
#describe books;
#insert into books (name,author,format,pages)
#values('Origin','Dan Brown','hardcover',480);
#select * from books;
#alter table books alter format set default 'hardcover';
#describe books;
#insert into books (name, author,pages) 
#values('A Man Called Ove','Frederik Backman',337);
#SELECT * FROM BOOKS;
#alter table books add check (pages > 0);
#update books set pages = -10 where name like '%Origin%';
#alter table books add constraint primary key (id);
#create table details (
#	id int primary key auto_increment,
#    language varchar(255),
#    publicher varchar(255),
#    book_id int,
#    foreign key (book_id) references books (id) );
#insert into details (language, publicher, book_id)
#values('English','Scribner',1);
#expected failure as no such id
#insert into details (language, publicher, book_id)
#values('English','Scribner',100);
#strings
#use website;
#select concat(first_name,' ',last_name) as full_name from customers;
#select upper(first_name) as upper_name from customers;
#select lower(first_name) as upper_name from customers;
#select upper(concat(first_name,' ',last_name)) as full_name from customers;
#select length(password) as password_len from customers;
#how to skip empty (spaces) at end and beginning (not between words): trim
#select length(trim(password)) as password_len from customers;
#select * from customers;
#select replace(country,'USA','United States') as country from customers;
