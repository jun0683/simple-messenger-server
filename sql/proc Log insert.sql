set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[insertLog]
(
	@userID int,
	@logState bit,
	@logresult bit OUTPUT
)
AS
BEGIN
	declare @state bit

	select @state = logstate
	from userlog
	where logtime = (select max(logtime)
						from userlog
						where userid = @userID)

	IF (@state IS NULL or @state = @logState)
		BEGIN
			set @logresult = 0;
		END
	ELSE
		BEGIN
			INSERT INTO userLog(userID,logTime,logState)
			VALUES (@userID,GETDATE(),@logState)
			SET @logresult = 1;
		END
END



