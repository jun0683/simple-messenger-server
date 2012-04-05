set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[didFriendsRequest]
(
	@friendID int
)
AS
BEGIN
	
	SELECT	userID
	FROM	friendRequest
	WHERE	friendID = @friendID and request = 1
	
	IF exists(select userID from friendRequest where friendID = @friendID and request = 1)
		return 1
	ELSE
		return 0
	
END









