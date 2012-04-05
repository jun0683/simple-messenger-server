set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[addFriendRequest]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	IF (exists(select userID from userInfo where userID = @userID) and exists(select userID from userInfo where userID = @friendID))
		BEGIN
		IF not exists(select * from friendRequest where userID = @userID and friendID = @friendID)
			BEGIN
			INSERT INTO friendRequest(userID,friendID,request)
			VALUES (@userID,@friendID,1)	
			return 1
			END
		END
	ELSE
		return 0
	
END




