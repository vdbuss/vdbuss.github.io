connect to gdbt;
drop table person;
create table person(id int primary key not null, name varchar(200));
insert into person values (1, 'person1'), (2, 'person2');
