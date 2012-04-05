set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[updateFriendRequestState]
(
	@userID int,
	@friendID int,
	@respond int
)
AS
BEGIN
	IF (EXISTS(select * from friendRequest WHERE friendID = @friendID and userid = @userid ))
		BEGIN
		UPDATE friendRequest
		SET request = @respond
		WHERE friendID = @friendID and userid = @userid
		return 1
		END
	ELSE
		return 0
END








