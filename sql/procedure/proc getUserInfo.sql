set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[getUserInfo]
(
	@loginID_	varchar(50),
	@pw_		varchar(10)
)
as
BEGIN
	SELECT * 
	from userinfo 
	where	loginID	= @loginID_ and pw = @pw_
	IF @@ROWCOUNT = 1
		BEGIN
		return 1
		END
	ELSE
		BEGIN
		return 0
		END
	
END