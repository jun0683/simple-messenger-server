select *
from chattingroom

select *
from chattingroomstate


-- make chatting room
declare @roomnumber int
exec @roomnumber = makechattingroom 1
print @roomnumber

-- isUserLogin
declare @state bit
exec @state = isuserlogin 7
print @state

-- insertLog
declare @loginState bit
exec insertLog 1,1,@loginState output
print @loginState

inviteChattingRoom