Create database Lab_5
go
use Lab_5
go

create table Users
(
User_ID int,
UserName varchar(20) primary key,
Age int,
Country varchar(20),
privacy int
)

go

INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (1,N'Ali123', 18, N'Pakistan',1)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (2,N'Aliza', 40, N'USA',1)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (3,N'Aysha', 19, N'Iran',0)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (4,N'DonaldTrump', 60, N'USA',0)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (5,N'ImranKhan', 55, N'Pakistan',0)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (6,N'Natasha', 28, N'USA',0)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (7,N'Samuel', 37, N'Australia',0)
INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (8,N'Sara', 30, N'Iran',1)



go

create table Following
(
FollowerUserName varchar(20) Foreign key References Users(UserName) ,
FollowedUserName varchar(20) Foreign key References Users(UserName),
primary key (FollowerUserName, FollowedUserName)
)

go

INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Ali123', N'DonaldTrump')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'Ali123')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'DonaldTrump')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'ImranKhan')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aysha', N'ImranKhan')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'DonaldTrump', N'ImranKhan')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'ImranKhan', N'DonaldTrump')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Natasha', N'ImranKhan')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Samuel', N'DonaldTrump')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Samuel', N'ImranKhan')
INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Sara', N'DonaldTrump')

go

Create table Tweets
(
TweetID int primary key,
UserName varchar(20) Foreign key References Users(UserName),
[Text] varchar(140)
)

go

INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (1, N'Ali123', N'Pakistan’s largest-ever population #Census  starts today in 63 districts after 19 years. ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (2, N'ImranKhan', N'Pakistan’s largest-ever population #Census  starts today in 63 districts after 19 years. ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (3, N'Sara', N'Take the soldier who come to our door for #Census as A ThankYou From Pakistan Army for our devotion. #CensusWithSupportOfArmy')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (4, N'ImranKhan', N'Pakistan is going to experience 6th #Census 2017.')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (5, N'Sara', N'Only #census can reveal where this aunty lives ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (6, N'ImranKhan', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (7, N'Sara', N'Over 1 million decrypted Gmail and Yahoo accounts allegedly up for sale on the Dark Web https://geekz0ne.fr/shaarli/?wQRSoQ  #piratage')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (8, N'Sara', N'Harry pot-head and the Sorcerer''s stoned')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (9, N'DonaldTrump', N'LSDespicable Me  #DrugMovies')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (10, N'ImranKhan', N'Forrest Bump #DrugMovies @midnight')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (12, N'DonaldTrump', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (13, N'Sara', N'#DrugMovies')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (14, N'DonaldTrump', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (15, N'Aliza', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')

go

Create table Likes
(
TweetID int Foreign key References Tweets(TweetID),
LikeByUserName varchar(20) Foreign key References Users(UserName),
LikeOnDate date
primary key (TweetID ,LikeByUserName)
)

GO
INSERT [dbo].[Likes] ([TweetID], [LikeByUserName], [LikeOnDate]) VALUES (1, N'Aliza', CAST(0x693C0B00 AS Date))
INSERT [dbo].[Likes] ([TweetID], [LikeByUserName], [LikeOnDate]) VALUES (2, N'Aliza', CAST(0x693C0B00 AS Date))
go

Create table Interests
(
InterestID int primary key,
[Description] varchar(30)
)

GO
INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (10, N'Politics')
INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (11, N'Sports')
INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (12, N'Movies')
INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (13, N'Education')
INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (14, N'Video Games')

go

create table UserInterests
(UserName varchar(20)  Foreign key References Users(UserName),
InterestID int Foreign key References Interests(InterestID)
primary key (UserName, InterestID)
 )
 
 GO
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 10)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 11)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 13)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 14)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 10)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 11)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 13)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 14)
INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'ImranKhan', 10)
 
 go

 Create table Hashtags
 (HashtagID int primary key,
 Hashtag varchar(30))
 
 GO
INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (1, N'#Census')
INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (2, N'#ClassiqueMatin')
INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (3, N'#MasseCritique')
INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (4, N'#piratage')
INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (5, N'#DrugMovies')

GO

-- 1

Select Max(Age) As "Maximum Age", Min(Age) As "Minimum Age", StDev(Age)  As "Std Dev of Age" From Users

-- 2

Select FollowedUserName as "User Name", Count(*) "No. of Followers"
From Following
Group By FollowedUserName
Having Count(*) >= All(Select Count(*) From Following Group By FollowedUserName)

-- 3

Select FollowedUserName, count(*) counts
From Following
Group By FollowedUserName
having count(*) = (Select max(counts)
 From (Select count(*) counts From Following Group by FollowedUserName
 Except 
 Select max(counts) From (Select count(*) counts From Following
 Group by FollowedUserName) as c1)as c2 )

-- 4

Select UserName From Users
Where UserName Not In(Select UserName From Tweets)

-- 5

Select  hashtags.Hashtag, users.UserName, counts
From Users, Hashtags, 
(
	Select username, hashtag ,count(*) counts From tweets, Hashtags
	Where Text like ('%' + Hashtag + '%') Group By UserName, hashtag 
) as c1 
Where Users.UserName = c1.UserName and hashtags.Hashtag = c1.Hashtag

-- 6

Select UserName From Users
Where Not Exists
(
	Select * From Tweets
	Where Users.UserName = Tweets.UserName And Text Like '%#Census%'
)

-- 7

Select UserName From Users
Where UserName Not In(Select FollowedUserName From Following)

-- 8

Select UserName From Users
Where  Not Exists(Select FollowedUserName From Following Where UserName = FollowedUserName)

-- 9

Select InterestID as "Interest ID",  Count(*) as "Counts"
From UserInterests
Group By InterestID
Having Count(*) >= All(Select Count(*) From UserInterests Group By InterestID)

Select InterestID as "Interest ID",  Count(*) as "Counts"
From UserInterests
Group By InterestID
Having Count(*) <= All(Select Count(*) From UserInterests Group By InterestID)

-- 10

Select Country, Count(*) As "Total Tweets" From Tweets
Join Users On(Tweets.UserName = Users.UserName)
Group By Country

-- 11

Select FollowedUserName From Following
Join Users On(Following.FollowerUserName = Users.UserName and Users.Country = 'Pakistan')

Select * From Following
Select * From Users
Select * From Tweets
Select * From Hashtags
Select * From Interests
Select * From UserInterests