--------------------
-- Abdullah Tahir --
-- 21L-5419		  --
-- 4J			  --
-- Assignment # 1 --
--------------------
Create Database Assignment_1
Use Assignment_1

Create Table Employee
(
   ID int NOT NULL,
   Name_ nvarchar(50) NOT NULL, 
   CNIC bigint NOT NULL,
   Dept nvarchar(50) NOT NULL,
   PhnNum bigint NOT NULL,
   Email nvarchar(50) NOT NULL
)

Create Table Employee_Login
(
    ID int NOT NULL,
    Password_ nvarchar(30) NOT NULL
)

Create Table Employee_Card
(
    empId int NOT NULL,
    cardNum int NOT NULL
)

Create Table Card_Details
(
    CardNum int NOT NULL,
    PIN int NOT NULL,
    ExpireDate_ Date NOT NULL, 
    Balance int NOT NULL
)

Create Table Department
(
    deptId nvarchar(30) NOT NULL,
    deptName nvarchar(30) NOT NULL
)

Create Table Venue
(
    ID nvarchar(30) NOT NULL
)

Create Table Online_Venue
(
    ID varchar(100) NOT NULL,
    totalCapacity int NOT NULL,
    venueName varchar(100) NOT NULL
)

Create Table Physical_Venue
(
    ID varchar(100) NOT NULL,
    totalCapacity int NOT NULL,
    venueName varchar(100) NOT NULL
)

Create Table Physical_Venue_Details
(
    ID varchar(100) NOT NULL,
    Date_ Date NOT NULL, 
    Status_ varchar(100) NOT NULL
)

Create Table All_Meetings
(
    ID int NOT NULL,
    venId varchar(100) NOT NULL, 
    empId int NOT NULL,
    DeptId varchar(100) NOT NULL,
    title varchar(100) NOT NULL,
    Date_ Date NOT NULL,
    mode varchar(100) NOT NULL,
    duration varchar(100) NOT NULL
)
 
Create Table Meeting_Participants
(
    MeetingID int NOT NULL,
    ParticipantId int NOT NULL
)

Insert Into Employee Values(1, 'Hassan', 3520224564741, 'D1', 03031111222, 'hassan123@gmail.com')
Insert Into Employee Values(2, 'Ali', 3520224564742, 'D2', 03032323123, 'ali123@gmail.com')
Insert Into Employee Values(3, 'Ahmad', 3520224564743, 'D1', 03031111333, 'Ahmad123@gmail.com')
Insert Into Employee Values(4, 'Jibran', 3520224564745, 'D3', 03031111338, 'Jibran123@gmail.com')
Insert Into Employee Values(5, 'Sana', 3520224564746, 'D1', 03034344333, 'Sana123@gmail.com')

Insert Into Employee_Login Values(1, 'Hello123')
Insert Into Employee_Login Values(2, 'Hi123535')
Insert Into Employee_Login Values(3, 'Ahmad344')
Insert Into Employee_Login Values(4, 'Jib12342')
Insert Into Employee_Login Values(5, 'Sana_123')

Insert Into Employee_Card Values(1, 12345678)
Insert Into Employee_Card Values(2, 13718232)
Insert Into Employee_Card Values(3, 13894789)
Insert Into Employee_Card Values(1, 23768478)

Insert Into Card_Details Values(12345678, 1234, '2024-12-11', 5000000)
Insert Into Card_Details Values(13718232, 1222, '2024-11-12', 133433)
Insert Into Card_Details Values(13894789, 1111, '2023-12-09', 10333)
Insert Into Card_Details Values(23768478, 2233, '2024-12-11', 340000)

Insert Into Department Values('D1', 'Marketing')
Insert Into Department Values('D2', 'Social Media')
Insert Into Department Values('D3', 'Sales')

Insert Into Venue Values('V1')
Insert Into Venue Values('V2')
Insert Into Venue Values('V3')
Insert Into Venue Values('V4')
Insert Into Venue Values('V5')

Insert Into Online_Venue Values('V2', 15, 'GoogleMeet')
Insert Into Online_Venue Values('V4', 11, 'Zoom')
Insert Into Online_Venue Values('V6', 12, 'Skype')

Insert Into Physical_Venue Values('V1', 15, 'Conference Room')
Insert Into Physical_Venue Values('V3', 20, 'Auditorium')
Insert Into Physical_Venue Values('V5', 11, 'Office')

Insert Into Physical_Venue_Details Values('V1', '2/16/23', 'booked')
Insert Into Physical_Venue_Details(ID, Date_, Status_) Values('V3', '2023/2/22', 'available')
Insert Into Physical_Venue_Details Values('V1', '3/16/23', 'available')

Insert Into All_Meetings Values(1, 'V1', 1, 'D1', 'Digital Marketing', '2/16/23', 'Physical ', '2 hrs')
Insert Into All_Meetings Values(2, 'V2', 3, 'D2', 'Instagram', '2023/2/21', 'Online', '1 hrs')
Insert Into All_Meetings Values(3, 'V3', 2, 'D3', 'Important Details', '2023/2/22', 'Physical ', '3 hrs')
Insert Into All_Meetings Values(4, 'V1', 1, 'D1', 'Tactics', '3/16/23', 'Physical ', '1 hr')

Insert Into Meeting_Participants Values(1, 2)
Insert Into Meeting_Participants Values(1, 3)
Insert Into Meeting_Participants Values(1, 4)
Insert Into Meeting_Participants Values(2, 1)
Insert Into Meeting_Participants Values(2, 4)

-- a 1

--Create View Meeting_Participant_Emails As
--
--Select am.ID AS Meeting_ID, am.venId AS Venue_ID, am.title 
--AS Meeting_Title, am.Date_ AS Meeting_Date, am.mode AS Meeting_Mode, am.duration
--AS Meeting_Duration, e.Email AS Participant_Email
--From All_Meetings am
--Join Meeting_Participants mp ON am.ID = mp.MeetingID
--Join Employee e ON mp.ParticipantId = e.ID;
--
--SELECT * FROM Meeting_Participant_Emails;

-- a 2

Select Count(Dept) As 'D1 Count'
From Employee
Where (Dept = 'D1')

-- a 3

Update Employee_Login
Set Password_ = 'fanta123'
Where (ID = 3)

-- a 4

Select Name_ As Host, deptName As 'Department Name', title As 'Meeting Title', Date_ As 'Date', mode As 'Mode', duration As 'Duration', venueName As 'Venue Name', totalCapacity As 'Total Capacity'
From All_Meetings
Join Physical_Venue On (Physical_Venue.ID = All_Meetings.venId)
Join Department On (Department.deptId = All_Meetings.DeptId)
Join Employee On (Employee.ID = All_Meetings.empID)
Where (mode = 'Physical')

-- a 5

Select * From All_Meetings
Where (Date_ = '2/16/23')

-- a 6

Select MeetingID, Count(*) As 'Members Count'
From Meeting_Participants
Group By MeetingID

-- a 7

Insert Into All_Meetings Values(4, 'V2', 1, 'D2', 'Data Base', '7/15/23', 'Online ', '1.4 hrs')

-- a 8

Delete From Meeting_Participants
Where MeetingID = (Select ID From All_Meetings Where title = 'Digital Marketing');
Delete From Physical_Venue_Details
Where ID = (Select venId From All_Meetings Where title = 'Digital Marketing');
Delete From All_Meetings
Where title = 'Digital Marketing';

-- a 9

Select ID From Employee
Except
Select empID From All_Meetings
Except
Select ParticipantID From Meeting_Participants

-- a 10

Select ID From Employee
Intersect
Select ParticipantID From Meeting_Participants

-- b 1

Select Top 1 Employee.Name_, Max(Card_Details.Balance) As Max_Bal
From Employee
Inner Join Employee_Card On(Employee.ID = Employee_Card.empId)
Inner Join Card_Details On (Employee_Card.cardNum = Card_Details.CardNum)
Group By Employee.Name_
Order By Max_Bal Desc

-- b 2

Select Top 1 Employee.Name_, Card_Details.Balance
From Employee
Inner Join Employee_Card On(Employee.ID = Employee_Card.empId)
Inner Join Card_Details On (Employee_Card.cardNum = Card_Details.CardNum)
Where Card_Details.Balance =
(
	Select Min(Balance)
	From Card_Details
	Where
	(
		Balance > (Select Min(Balance)
		From Card_Details
	)
)

-- b 3

Select title As 'Meeting Title', venueName As 'Venue Name', totalCapacity As 'Total Capacity'
From All_Meetings
Join Online_Venue On (Online_Venue.ID = All_Meetings.venId)
Join Employee On (Employee.ID = All_Meetings.empID)
Where (mode = 'Online')

-- b 4

Select Top 1 MeetingID, Count(*) As 'Members Count'
From Meeting_Participants
Group By MeetingID
Order By 'Members Count' Desc

-- b 5

Select Top 1 venID As Venue,  Count(*) As 'Max Meetings', Coalesce (Online_Venue.venueName , Physical_Venue.venueName) As Venue
From All_Meetings
Left Join Physical_Venue On (Physical_Venue.ID = venID)
Left Join Online_Venue On (Online_Venue.ID = venID)
Group By venId, Online_Venue.venueName, Physical_Venue.venueName
Order By venId Asc