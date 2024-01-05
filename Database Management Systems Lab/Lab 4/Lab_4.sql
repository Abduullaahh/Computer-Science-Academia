Create DataBase Lab_4
Use Lab_4

create table [User]
(
	[userId] int primary key,
	[name] varchar(20) not null,
	[phoneNum] varchar(15) not null,
	[city] varchar(20) not null
)

create table CardType
(
	[cardTypeID] int primary key,
	[name] varchar(15),
	[description] varchar(40) null
)

create Table [Card]
(
	cardNum Varchar(20) primary key,
	cardTypeID int foreign key references  CardType([cardTypeID]),
	PIN varchar(4) not null,
	[expireDate] date not null,
	balance float not null
)

Create table UserCard
(
	userID int foreign key references [User]([userId]),
	cardNum varchar(20) foreign key references [Card](cardNum),
	primary key(cardNum)
)

create table [Transaction]
(
	transId int primary key,
	transDate date not null,
	cardNum varchar(20) foreign key references [Card](cardNum),
	amount int not null
)

INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)


Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]

-- 1

SELECT ct.name as cardType, COUNT(DISTINCT uc.userID) as uniqueUsers
FROM Card c
JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
JOIN UserCard uc ON c.cardNum = uc.cardNum
GROUP BY ct.name

-- 2

SELECT u.name as userName, c.cardNum, ct.name as cardType, c.expireDate, c.balance
FROM [User] u
JOIN UserCard uc ON u.userId = uc.userId
JOIN Card c ON uc.cardNum = c.cardNum
JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
ORDER BY u.name, c.cardNum

-- 3

-- (a)

SELECT [name] FROM [User]
EXCEPT
SELECT [User].[name] FROM [User]
JOIN [UserCard] ON [User].[userId] = [UserCard].[userID]

-- (b)

SELECT [User].[name] FROM [User]
LEFT JOIN [UserCard] ON [User].[userId] = [UserCard].[userID]
WHERE [UserCard].[userID] IS NULL

-- 4

SELECT [Card].[cardNum], [CardType].[name] AS [cardType], [User].[name] AS [ownerName]
FROM [Card]
LEFT JOIN [Transaction] ON [Card].[cardNum] = [Transaction].[cardNum]
LEFT JOIN [UserCard] ON [Card].[cardNum] = [UserCard].[cardNum]
LEFT JOIN [User] ON [UserCard].[userID] = [User].[userId]
WHERE [Transaction].[transId] IS NULL

-- 5

SELECT c.cardNum, ct.name AS cardTypeName, u.name AS ownerName
FROM Card c
JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
JOIN UserCard uc ON c.cardNum = uc.cardNum
JOIN [User] u ON uc.userID = u.userId
LEFT JOIN [Transaction] t ON c.cardNum = t.cardNum
WHERE t.transId IS NULL OR t.transDate < DATEADD(year, -1, GETDATE())

-- 6

SELECT 
    ct.name AS CardType, 
    COUNT(DISTINCT c.cardNum) AS TotalCards
FROM 
    CardType ct
    INNER JOIN Card c ON ct.cardTypeID = c.cardTypeID
    INNER JOIN [Transaction] t ON c.cardNum = t.cardNum
WHERE 
    t.transDate BETWEEN '2015-01-01' AND '2017-12-31'
GROUP BY 
    ct.name
HAVING 
    SUM(t.amount) > 6000

-- 7

SELECT u.userId, u.name, u.phoneNum, u.city, c.cardNum, ct.name AS cardType
FROM [User] u
INNER JOIN UserCard uc ON u.userId = uc.userID
INNER JOIN [Card] c ON uc.cardNum = c.cardNum
INNER JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
WHERE c.expireDate BETWEEN GETDATE() AND DATEADD(MONTH, 3, GETDATE())

-- 8

SELECT u.userId, u.name
FROM [User] u
INNER JOIN UserCard uc ON u.userId = uc.userId
INNER JOIN Card c ON uc.cardNum = c.cardNum
GROUP BY u.userId, u.name
HAVING SUM(c.balance) >= 5000

-- 9

SELECT c1.cardNum, c2.cardNum, YEAR(c1.expireDate) as expireYear
FROM Card c1
JOIN Card c2 ON c1.expireDate = c2.expireDate AND c1.cardNum != c2.cardNum
WHERE YEAR(c1.expireDate) = YEAR(c2.expireDate)
ORDER BY expireYear;

-- 10

SELECT u1.name, u2.name
FROM [User] u1
JOIN [User] u2 ON LEFT(u1.name, 1) = LEFT(u2.name, 1) AND u1.userId <> u2.userId
ORDER BY u1.name, u2.name

-- 11

SELECT u.userId, u.name
FROM [User] u
INNER JOIN (
    SELECT uc.userID
    FROM UserCard uc
    INNER JOIN Card c ON uc.cardNum = c.cardNum
    INNER JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
    WHERE ct.name = 'Debit'
) d ON u.userId = d.userID
INNER JOIN (
    SELECT uc.userID
    FROM UserCard uc
    INNER JOIN Card c ON uc.cardNum = c.cardNum
    INNER JOIN CardType ct ON c.cardTypeID = ct.cardTypeID
    WHERE ct.name = 'Credit'
) c ON u.userId = c.userID;

-- 12

SELECT u.city, COUNT(DISTINCT u.userId) AS NumOfUsers, SUM(t.amount) AS TotalAmount
FROM [User] u
JOIN UserCard uc ON u.userId = uc.userID
JOIN Card c ON uc.cardNum = c.cardNum
JOIN [Transaction] t ON c.cardNum = t.cardNum
GROUP BY u.city