set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[findUser]
(
	@loginID	varchar(50)
)
AS
BEGIN
	select userid from userInfo where loginID = @loginID;
	IF @@ROWCOUNT != 0
		BEGIN
		return 1;
		END
	ELSE
		BEGIN
		return 0;
		END
END