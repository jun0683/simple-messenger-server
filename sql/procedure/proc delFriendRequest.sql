set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[delFriendRequest]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	IF exists(select * from friendRequest where friendID = @friendID and userid = @userid)
		BEGIN
		DELETE FROM friendRequest
		WHERE friendID = @friendID and userid = @userid
		return 1
		END
	ELSE
		BEGIN
		return 0
		END
END




