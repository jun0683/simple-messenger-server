set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
create proc [dbo].[getUserID]
(
	@loginID	varchar(50)
)
as
BEGIN
	SELECT userid
	from userinfo 
	where	loginID	= @loginID
	IF @@ROWCOUNT = 1
		BEGIN
		return 1
		END
	ELSE
		BEGIN
		return 0
		END
	
END