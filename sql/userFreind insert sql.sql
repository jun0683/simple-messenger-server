declare @userid1 int,@userid2 int

set @userid1 = 9
set @userid2 = 16

INSERT INTO [messenger].[dbo].[userFriends]
           ([userID]
           ,[userFriend])
     VALUES
           (@userid1,
            @userid2)

INSERT INTO [messenger].[dbo].[userFriends]
           ([userID]
           ,[userFriend])
     VALUES
           (@userid2,
            @userid1)