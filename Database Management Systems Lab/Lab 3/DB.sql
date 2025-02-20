create database lab_3
	use lab_3

	create table salesman
	(
		salesman_id int not null,
		name nvarchar(100) not null,
		city nvarchar(100) not null,
		comission decimal not null
	)

	create table orders
	(
		ord_no int not null,
		purch_amt decimal not null,
		ord_date date not null,
		customer_id int not null,
		salesman_id int
	)

	create table customers
	(
		customer_id int not null,
		cust_name nvarchar(100) not null,
		city nvarchar(100) not null,
		grade int,
		salesman_id int not null
	)


	insert into salesman values(5001,'James Hoog','New York', 0.15)
	insert into salesman values(5002,'Nail Knite','Paris', 0.13)
	insert into salesman values(5005,'Pit Alex','London', 0.11)
	insert into salesman values(5006,'Mc Lyon','Paris',	0.14)
	insert into salesman values(5007,'Paul Adam','San Jose', 0.13)
	insert into salesman values(5003,'Lauson Hen','San Jose', 0.12)

	insert into orders values(70001, 150.5 	, '2012-10-05', 3005,	5006)
	insert into orders values(70009, 270.65 , '2011-09-10', 3001,	5005)
	insert into orders values(70002, 65.26 	, '2014-10-05', 3002,	5001)
	insert into orders values(70004, 110.5 	, '2011-08-17', 3009,	5003)
	insert into orders values(70007, 948.5 	, '2012-09-10', 3005,	5006)
	insert into orders values(70005, 2400.6 , '2010-07-27', 3007,	5001)
	insert into orders values(70008, 5760 	, '2013-09-10', 3002,	5001)
	insert into orders values(70010, 1983.43, '2010-10-10', 3004,	5005)
	insert into orders values(70003, 2480.4 , '2013-10-10', 3009,	5003)
	insert into orders values(70012, 250.45 , '2010-06-27', 3008,	5002)
	insert into orders values(70011, 75.29 	, '2014-08-17', 3003,	null)
	insert into orders values(70013, 3045.6 , '2010-04-25', 3002,	null)

	insert into customers values(3002,'Nick Rimando','New York',100,5001)
	insert into customers values(3007,'John Brad Davis','New York',200,5001)
	insert into customers values(3005,'Graham Zusi','California',200,5002)
	insert into customers values(3008,'Julian Green','London',300,5002)
	insert into customers values(3004,'Fabian Johnson','Paris',300,5006)
	insert into customers values(3009,'Geoff Cameron','Berlin',100,5003)
	insert into customers values(3003,'Jozy Altidor','Moscow',200,5007)
	insert into customers values(3001,'John Brad Guzan','London',null,5005)

	alter table salesman add constraint PK_salesman primary key(salesman_id)

	alter table orders add constraint PK_orders primary key(ord_no)

	alter table customers add constraint PK_customers primary key(customer_id)

	alter table orders add constraint FK_orders_salesman_id foreign key (salesman_id) references salesman (salesman_id);

    alter table customers add constraint FK_customers_salesman_id foreign key (salesman_id) references salesman (salesman_id);

    select salesman_id, city from salesman;

    select * from customers where city = 'New York' order by cust_name asc;

	sp_rename 'salesman.name', 'full_name', 'column'

	select * from salesman

	select * from customers where cust_name LIKE '%John%' and (city = 'London' or city = 'Paris' or city = 'New York');

	select cust_name from customers where cust_name LIKE '%a%';

	select * from orders order by ord_date DESC;

	select * from orders where month(ord_date) = 1;

	select datepart (year, ord_date), datepart (week, ord_date), datepart (DAYOFYEAR, ord_date), datepart (month, ord_date), datepart (month, ord_date), datepart (weekday, ord_date)
	from orders
	where month(ord_date) = 10

	select * from customers where customer_id
	in (select customer_id from orders where YEAR(ord_date)
	in (2012, 2014) group by customer_id
	having count(distinct YEAR(ord_date)) = 2);

	select * from customers where customer_id
	in (select customer_id from orders where YEAR(ord_date) = 2012) and customer_id NOT
	in (select customer_id from orders where YEAR(ord_date) = 2014);

	update orders SET purch_amt = purch_amt * 3 where month(ord_date) = 10;

	update salesman SET comission = comission + 0.5 where city = 'San Jose';

	select name, ord_date, comission
	from salesman, orders
	where salesman.salesman_id = orders.salesman_id;