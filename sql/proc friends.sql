set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER proc [dbo].[friends]
@userID int
as
select f.userfriend, u.loginid, u.pw, u.username
from userFriends f inner join userInfo u
	on f.userfriend = u.userid
where f.userid = @userID
