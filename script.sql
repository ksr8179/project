drop database db;

create database db;
use db;

set character_set_client = utf8;
set character_set_connection = utf8;
set character_set_results = utf8;
set character_set_server = utf8;
set character_set_database = utf8;

drop table login;
drop table book;

truncate table login;
truncate table book;

create table login(
	id varchar(15) not null,
	pwd varchar(15) not null,
	chk varchar(15) not null,
constraint unique(id)
);

create table book(
	name varchar(30) not null,
	writer varchar(30) not null,
	publisher varchar(30) not null,
	amount varchar(10) default 1
);

insert into login
values("asd","1234","1");

alter table book modify column name varchar(30) character set utf8 collate utf8_general_ci;
alter table book modify column writer varchar(30) character set utf8 collate utf8_general_ci;
alter table book modify column publisher varchar(30) character set utf8 collate utf8_general_ci;
alter table book modify column amount varchar(10) character set utf8 collate utf8_general_ci;


insert into book
values("linux programming","lee,kim","duyangsa","1");
insert into book
values("power java","chhun,ha","infinity books","1");
insert into book
values("operating system","jo,go,park","gyobomungo","1");
