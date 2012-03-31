set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[withdrawUser]
(
	@loginID	varchar(50),
	@pw			varchar(50)
)
AS
	DECLARE @userID INT
	set @userID = (select userID from userInfo where loginID = @loginID and pw = @pw)
	IF @userID IS NULL
		return 0;
	ELSE
		BEGIN
		DELETE FROM userLog WHERE userID = @userID;
		DELETE FROM chattingRoomState WHERE userID = @userID;
		DELETE FROM chattingMessage WHERE sendUserID = @userID;
		DELETE FROM chattingRoom WHERE createUserID = @userID;
		DELETE FROM userFriends WHERE userID = @userID or userFriend = @userID;
		DELETE FROM userInfo WHERE userID = @userID;

		return 1;
		END
