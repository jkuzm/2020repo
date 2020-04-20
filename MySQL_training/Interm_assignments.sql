#select users.first_name,comments.comment_id from users
#	inner join comments on users.user_id=comments.user_id;
#---block of review of basics---
#show databases;
use store;
#show tables;
#select distinct country from brands;
#select country from brands where country like '%ea';
#select distinct country from brands order by country;
#select * from brands order by country desc;
#set SQL_SAFE_UPDATES = 0;
#insert into brands (id,name) values (10,'Ulta');
#delete from brands where id=10;
#select country,min(founded) from brands group by country;
#select * from brands order by founded desc limit 1;
#---end of basics review----
#select * from brands;
#select * from shoes;
#SELECT brands.name, AVG(shoes.price)
#FROM brands INNER JOIN shoes ON brands.id = shoes.brand_id
#GROUP BY brands.name ORDER BY brands.name;
#assignment 6
#select brands.name,count(shoes.name) from brands LEFT JOIN shoes
#on  group by brands.name order by brands.name; 
#select shoes.name,shoes.price,brands.country from brands right join shoes
#on brands.id = shoes.brand_id order by brands.country desc;
#create database blog;
#use blog;

/*create table posts (
	id int primary key auto_increment,
    title varchar(255) not null unique,
    text TEXT not null,
    author varchar(50) default 'admin',
    date date not null,
    status enum('draft','publish','private') default 'draft',
    likes int default 0,
    dislikes int default 0
);*/
describe posts;