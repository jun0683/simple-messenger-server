set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[makeChattingRoom]
	@userID int
AS
	INSERT INTO chattingroom(createUserID,createTime)
	VALUES (@userID,GETDATE())
	return @@IDENTITY;
