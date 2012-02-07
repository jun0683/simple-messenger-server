set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO

ALTER proc [dbo].[registerNewUser]
	@loginID	varchar(50),
	@pw			varchar(50),	
	@userName		nvarchar(50)
as
begin
	DECLARE @err INT;
	
	IF exists(select loginID from userInfo where loginID = @loginID)
		return 1;
	ELSE
		INSERT INTO userInfo(loginID,pw,userName)
	     VALUES(@loginID,@pw,@userName)
		set @err = @@ERROR;
		RETURN @err;
end

