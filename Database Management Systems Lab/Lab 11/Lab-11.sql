Create DatabAse q

use q

Create Table Department
(
	deptid int Primary key,
	dname varchar(80) not null
)

Create Table Student
(
	rollno int Primary key,
	name varchar (80) not null,
	dept_id int foreign key references Department (deptid),
	batch int not null
)

Create Table Course
(
	Courseid int Primary key,
	cname varchar(80) not null,
	credithrs int not null,
	deptid int foreign key references Department (deptid)
)

Create Table SectiOn
(
	SectiOnid int Primary key,
	Courseid int foreign key references Course (Courseid),
	capacity int not null
)

Create Table Enrolled
(
	Studentrollno int foreign key references Student (rollno),
	SectiOnid int foreign key references SectiOn (SectiOnid)
	Primary key(Studentrollno,SectiOnid)
)

Create Table Faculty
(
	Facultyid int Primary key,
	fname varchar(80) not null,
	deptid int foreign key references Department (deptid)
)


Insert Into Department (deptid, dname) Values (1, 'Computer Science');
Insert Into Department (deptid, dname) Values (2, 'Electrical Engineering');
Insert Into Department (deptid, dname) Values (3, 'Mechanical Engineering');


Insert Into Student (rollno, name, dept_id, batch) Values (1001, 'John Doe', 1, 2023);
Insert Into Student (rollno, name, dept_id, batch) Values (1002, 'Jane Smith', 2, 2022);
Insert Into Student (rollno, name, dept_id, batch) Values (1003, 'Bob JohnsOn', 1, 2024);


Insert Into Course (Courseid, cname, credithrs, deptid) Values (101, 'Data Structures', 3, 1);
Insert Into Course (Courseid, cname, credithrs, deptid) Values (102, 'Digital Signal Processing', 4, 2);
Insert Into Course (Courseid, cname, credithrs, deptid) Values (103, 'Mechanics', 4, 3);


Insert Into SectiOn (SectiOnid, Courseid, capacity) Values (201, 101, 50);
Insert Into SectiOn (SectiOnid, Courseid, capacity) Values (202, 102, 40);
Insert Into SectiOn (SectiOnid, Courseid, capacity) Values (203, 103, 30);
Insert Into SectiOn (SectiOnid, Courseid, capacity) Values (204, 101, 30);


Insert Into Enrolled (Studentrollno, SectiOnid) Values (1001, 201);
Insert Into Enrolled (Studentrollno, SectiOnid) Values (1002, 202);
Insert Into Enrolled (Studentrollno, SectiOnid) Values (1003, 203);


Insert Into Faculty (Facultyid, fname, deptid) Values (501, 'Dr. Smith', 1);
Insert Into Faculty (Facultyid, fname, deptid) Values (502, 'Dr. JohnsOn', 2);
Insert Into Faculty (Facultyid, fname, deptid) Values (503, 'Dr. Brown', 3);


Select * From Faculty
Select * From Enrolled
Select * From SectiOn
Select * From Course
Select * From Student
Select * From Department

-- Q#1

Create Table Auditing
(
	AuditID int Identity(1,1) Primary key,--auto increment
	LastChangeOn date not null
)

Go
Create Trigger q1
On Department
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate())
End

Disable Trigger q1 On Department--for next questiOn
Go
Create Trigger q11
On Student
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate())
End

Disable Trigger q11 On Student--for next questiOn
Go
Create Trigger q111
On Faculty
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate())
End

Disable Trigger q111 On Faculty--for next questiOn

Update Faculty Set fname = 'Dr.Umer' Where Facultyid = 501

Select * From Auditing

-- Q#2

Alter Table Auditing add descriptiOn varchar(20)

Go
Create Trigger q222
On Faculty
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate(),'Faculty')
End

Go
Create Trigger q2
On Department
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate(),'Department')
End

Go
Create Trigger q22
On Student
After Update,Insert,Delete
As Begin
Insert Into Auditing Values(getdate(),'Student')
End

Go

Update Faculty Set fname = 'Dr.Ahmad' Where Facultyid = 501

Select * From Auditing

-- Q#3

Go
Create view enrollment
As
Select Course.Courseid,Course.cname,SectiOn.SectiOnid,SectiOn.capacity
From Course
Join SectiOn On Course.Courseid = SectiOn.Courseid

-- Q#4

Go
Create Procedure enrollment1
@Studentid int,
@Courseid int,
@SectiOnid int
As Begin
Declare @capacity int
Select @capacity=capacity From enrollment
Where Courseid=@Courseid and SectiOnid=@SectiOnid
if(@capacity>0)
	Begin
	Insert Into Enrolled Values(@Studentid,@SectiOnid)
	End
else
	print 'Unable to Insert'
	End

execute enrollment1 1003,102,202

Select * From Enrolled

-- Q#5

Go
Create Trigger q5
On Department
instead of Update,Insert,Delete
As Begin
print 'Modify Departments not Allowed'
End

Insert Into Department Values(4,'CV')

-- Q#6

Go
Create Trigger q6
On databAse
for Alter_Table,drop_Table
As Begin
print 'Alter or Drop not Allowed'
End