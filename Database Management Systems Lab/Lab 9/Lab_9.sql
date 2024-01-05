use master
go
drop  database ATM
go 
Create database ATM
go 
use ATM
go

create table [User](
[userId] int primary key,
[name] varchar(20) not null,
[phoneNum] varchar(15) not null,
[city] varchar(20) not null
)
go

create table CardType(
[cardTypeID] int primary key,
[name] varchar(15),
[description] varchar(40) null
)
go
create Table [Card](
cardNum Varchar(20) primary key,
cardTypeID int foreign key references  CardType([cardTypeID]),
PIN varchar(4) not null,
[expireDate] date not null,
balance float not null
)
go


Create table UserCard(
userID int foreign key references [User]([userId]),
cardNum varchar(20) foreign key references [Card](cardNum),
primary key(cardNum)
)
go
create table [Transaction](
transId int primary key,
transDate date not null,
cardNum varchar(20) foreign key references [Card](cardNum),
amount int not null
)


INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')
GO


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
GO
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')
GO

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)
GO

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
GO
Insert  [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)
GO

--query 1
create function q1(@num int)
returns float 
as 
begin

declare @returnval float
select @returnval=[Card].balance from [Card] where [Card].cardNum=@num
return @returnval
end

select dbo.q1(1238) as balance

--query 2
create function dbo.q2(@id int)
returns table
as
return select*
from [User] where [User].userId=@id

select *from dbo.q2(1)

--query 3
create procedure detail1
@name varchar(20)
as
begin 
 select *from [user] where name=@name
end 
go

declare @name1 varchar(20)='Ahmed'
execute detail1
@name=@name1

--query 4
create procedure q6
@id int
as 
begin
   select dbo.q2.userId,UserCard.cardNum, dbo.q1(UserCard.cardNum) as balance from dbo.q2(@id) inner join UserCard on UserCard.userID=dbo.q2.userId

end
go

declare @id1 int=1
execute q6
@id=@id1

--query 5
create function dbo.q7(@id int)
returns table
as
return  select dbo.q2.userId,UserCard.cardNum, dbo.q1(UserCard.cardNum) as balance from dbo.q2(@id) inner join UserCard on UserCard.userID=dbo.q2.userId

select *from dbo.q7(1)
--query 6
create procedure countcards5
@id int,
@no_cards int output
as 
begin
   select @no_cards=(select count( UserCard.userId)as count from [User]inner join UserCard on UserCard.userID=[User].userId 
   where UserCard.userid=@id
   group by [User].userID)
end
go

declare  @id1 int=1,@no int
execute countcards5
@id=@id1,
@no_cards=@no output
select @no as no_cards
go

--query 7
create procedure login2
@num varchar(20),
@pin varchar(4),
@status int output
as
begin
   if exists( Select cardnum,pin from [Card]  where cardnum=@num and pin=@pin)
   begin
   set @status=1
   end
   else
   begin
   set @status=0
   end
end
go

declare @num1 varchar(20)='1324327436569', @pin1 varchar(4)='1770',@s int
execute login2
@num=@num1,
@pin=@pin1,
@status=@s output
select @s as validity

--Yes we can write the same query in UDF which works same by giving two input parameters and getting ouput by udf inline

--8 query
create procedure update2
@num varchar(20),
@updatedpin varchar(4),
@pin varchar(4),
@status varchar(20) output

as 
begin 
 if exists( Select cardnum,pin from [Card]  where cardnum=@num and pin=@pin and LEN(@updatedpin)=4 )
   begin

   update [card]
   set pin=@updatedpin
   where pin=@pin

   set @status='Updated Pin'
   end
 else
 begin
  set @status='Error'
 end  
end
go

declare @num1 varchar(20)='1324327436569', @pin1 varchar(4)='1770',@up varchar(4)='2002',@g varchar(20)
execute update2
@num=@num1,@pin=@pin1,@updatedpin=@up,@status=@g output
select @g

--9 query
create procedure WithDraw1
@cardnum varchar(20), @pin varchar(4), @amount int
AS
BEGIN
if exists (select * from [card] where [card].cardNum = @cardnum and [card].PIN = @pin and @amount < [card].balance) and @amount > 0
BEGIN
DECLARE @maxtransid int;
select @maxtransid = MAX(transid)from dbo.[Transaction]

insert into [transaction]
values (@maxtransid+1,CAST(GETDATE() AS Date),@cardnum,@amount);

update [card]
set balance = balance - @amount
where cardNum = @cardnum

END
else
if exists (select * from [card] where [card].cardNum = @cardnum and [card].PIN = @pin)
BEGIN
DECLARE @maxtransid2 int;
select @maxtransid2 = MAX(transid)from dbo.[Transaction]

insert into [transaction]
values (@maxtransid2+1,CAST(GETDATE() AS Date),@cardnum,@amount);
END 
END
GO

Declare @card varchar(20) ,@pincode varchar(4) ,@amount int;
EXECUTE WithDraw1
@cardnum = '1235', @pin = '9234', @amount = 2000

--yes we can also write in udf by giving cardnum,pin,amount of transaction as input adn then getting output by inline udf

select * from [Transaction]
select * from [card]

Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]