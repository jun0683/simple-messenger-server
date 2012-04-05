set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[addFriend]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	
	IF exists(select userID from userFriends where userFriend = @friendID and userID = @userID)
		BEGIN
		return 0
		END
	ELSE
		BEGIN
		INSERT userFriends
		values (@userID,@friendID)
		return 1
		END

END














