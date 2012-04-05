set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[delFriend]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	
	IF exists(select userID from userFriends where userFriend = @friendID and userID = @userID)
		DELETE FROM userFriends
		WHERE userFriend = @friendID and userID = @userID
		
		DELETE FROM userFriends
		WHERE userFriend = @userID and userID = @friendID		

END












