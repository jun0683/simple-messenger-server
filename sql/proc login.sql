set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[login]
(
	@loginID_	varchar(50),
	@pw_		varchar(10)
)
as
	SELECT *
		from userinfo
		where	loginID	= @loginID_ and
				pw		= @pw_
	

