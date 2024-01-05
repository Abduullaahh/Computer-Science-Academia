Create DataBase Lab_6_21L_5419

Use  Lab_6_21L_5419

	SET ANSI_NULLS ON
	GO
	SET QUOTED_IDENTIFIER ON
	GO
	SET ANSI_PADDING ON
	GO

	CREATE TABLE [dbo].[Items]
	(
		[ItemNo] [int] NOT NULL,
		[Name] [varchar](10) NULL,
		[Price] [int] NULL,
		[Quantity in Store] [int] NULL,
		PRIMARY KEY CLUSTERED 
		(
			[ItemNo] ASC
		)
		WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
	)	ON [PRIMARY]
	GO
	
	SET ANSI_PADDING OFF
	
	GO
	INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (100, N'A', 1000, 100)
	INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (200, N'B', 2000, 50)
	INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (300, N'C', 3000, 60)
	INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (400, N'D', 6000, 400)
	/****** Object:  Table [dbo].[Courses]    Script Date: 02/17/2017 13:04:02 ******/
	
	SET ANSI_NULLS ON
	GO
	SET QUOTED_IDENTIFIER ON
	GO
	SET ANSI_PADDING ON
	GO
	
	CREATE TABLE [dbo].[Customers]
	(
		[CustomerNo] [varchar](2) NOT NULL,
		[Name] [varchar](30) NULL,
		[City] [varchar](3) NULL,
		[Phone] [varchar](11) NULL,
		PRIMARY KEY CLUSTERED 
		(
			[CustomerNo] ASC
		)
		WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
	)	ON [PRIMARY]
	
	GO
	SET ANSI_PADDING OFF
	GO
	
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C1', N'AHMED ALI', N'LHR', N'111111')
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C2', N'ALI', N'LHR', N'222222')
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C3', N'AYESHA', N'LHR', N'333333')
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C4', N'BILAL', N'KHI', N'444444')
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C5', N'SADAF', N'KHI', N'555555')
	INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C6', N'FARAH', N'ISL', NULL)
	/****** Object:  Table [dbo].[Orders]    Script Date: 02/17/2017 13:04:03 ******/
	
	SET ANSI_NULLS ON
	GO
	SET QUOTED_IDENTIFIER ON
	GO
	SET ANSI_PADDING ON
	GO
	
	CREATE TABLE [dbo].[Orders]
	(
		[OrderNo] [int] NOT NULL,
		[CustomerNo] [varchar](2) NULL,
		[Date] [date] NULL,
		[Total_Items_Ordered] [int] NULL,
		PRIMARY KEY CLUSTERED 
		(
			[OrderNo] ASC
		)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
	)	ON [PRIMARY]
	
	GO
	SET ANSI_PADDING OFF
	GO
	INSERT [dbo].[Orders] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (1, N'C1', CAST(0x7F360B00 AS Date), 30)
	INSERT [dbo].[Orders] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (2, N'C3', CAST(0x2A3C0B00 AS Date), 5)
	INSERT [dbo].[Orders] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (3, N'C3', CAST(0x493C0B00 AS Date), 20)
	INSERT [dbo].[Orders] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (4, N'C4', CAST(0x4A3C0B00 AS Date), 15)
	/****** Object:  Table [dbo].[OrderDetails]    Script Date: 02/17/2017 13:04:03 ******/
	
	SET ANSI_NULLS ON
	GO
	SET QUOTED_IDENTIFIER ON
	GO
	
	CREATE TABLE [dbo].[OrderDetails]
	(
		[OrderNo] [int] NOT NULL,
		[ItemNo] [int] NOT NULL,
		[Quantity] [int] NULL,
		PRIMARY KEY CLUSTERED 
		(
			[OrderNo] ASC,
			[ItemNo] ASC
		)
		WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
	)	ON [PRIMARY]
	
	GO
	INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (1, 200, 20)
	INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (1, 400, 10)
	INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (2, 200, 5)
	INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (3, 200, 60)
	GO
	
	/****** Object:  ForeignKey [FK__OrderDeta__ItemN__4316F928]    Script Date: 02/03/2017 13:55:38 ******/
	ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD FOREIGN KEY([ItemNo])
	REFERENCES [dbo].[Items] ([ItemNo])
	GO

	/****** Object:  ForeignKey [FK__OrderDeta__Order__4222D4EF]    Script Date: 02/03/2017 13:55:38 ******/
	ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD FOREIGN KEY([OrderNo])
	REFERENCES [dbo].[Orders] ([OrderNo])



Select * from Orders
Select * from OrderDetails
Select * from Items
Select * from Customers

-- 1

Create View [prices]
AS
Select OrderNo, Sum(OrderDetails.Quantity*Items.Price) as Price
From OrderDetails, Items
Where (OrderDetails.ItemNo = Items.ItemNo)
Group By OrderNo

Select * From [prices]

-- 2

Create View [MoreThenTwenty]
AS
Select Name From Items
Join OrderDetails On (Items.ItemNo = OrderDetails.ItemNo)
Where
(
	OrderDetails.Quantity > 20
)

Select * From [MoreThenTwenty]

-- 3

Create View [StarCustomers]
AS
Select Distinct Customers.Name From Customers
Join Orders On (Orders.CustomerNo = Customers.CustomerNo)
join OrderDetails On (OrderDetails.OrderNo = Orders.OrderNo)
Join Items On (Items.ItemNo = OrderDetails.ItemNo)
Where
(
	(Items.Price * OrderDetails.Quantity) > 2000
)

Select * From [StarCustomers]

-- 4

Create View [phone_number_not_null]
AS
Select Name From Customers
Where
(
	Phone Is Not Null
)

Select * From [phone_number_not_null]

--With Check Option

CREATE VIEW [dbo].[phone_number_not_null_check]
--WITH CHECK OPTION
AS
SELECT [CustomerNo], [Name], [City], [Phone]
FROM [dbo].[Customers]
WHERE [Phone] IS NOT NULL

Select * From [dbo].[phone_number_not_null_check]


-- Insert
INSERT INTO [dbo].[phone_number_not_null_check] ([CustomerNo], [Name], [City], [Phone])
VALUES (N'C7', N'ZAINAB', N'ISL', N'777777')

INSERT INTO [dbo].[phone_number_not_null_check] ([CustomerNo], [Name], [City], [Phone])
VALUES (N'C8', N'ASAD', N'LHR', NULL)

-- Update
UPDATE [dbo].[phone_number_not_null_check]
SET [City] = N'KHI'
WHERE [CustomerNo] = N'C1'

UPDATE [dbo].[phone_number_not_null_check]
SET [City] = N'KHI'
WHERE [CustomerNo] = N'C2'

-- Delete
DELETE FROM [dbo].[phone_number_not_null_check]
WHERE [CustomerNo] = N'C6'

DELETE FROM [dbo].[phone_number_not_null_check]
WHERE [CustomerNo] = N'C5'

-- Stored Procedures
-- 1

CREATE PROCEDURE sp_GetOrdersByCustomer
	@CustomerNo varchar(2)
AS
BEGIN
	SELECT *
	FROM Orders
	WHERE CustomerNo = @CustomerNo
END

-- 2

CREATE PROCEDURE sp_GetOrderDetails
	@OrderNo int
AS
BEGIN
	SELECT 
		C.Name AS CustomerName,
		O.Date AS OrderDate,
		O.Total_Items_Ordered,
		I.Name AS ItemName
	FROM Orders O
	INNER JOIN Customers C ON O.CustomerNo = C.CustomerNo
	INNER JOIN Order_Items OI ON O.OrderNo = OI.OrderNo
	INNER JOIN Items I ON OI.ItemNo = I.ItemNo
	WHERE O.OrderNo = @OrderNo
END


-- 3

CREATE PROCEDURE sp_GetCustomersByCity
	@City varchar(3)
AS
BEGIN
	SELECT *
	FROM Customers
	WHERE City = @City
END
