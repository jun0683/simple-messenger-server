
update userInfo
set loginID = RTRIM(LTRIM(loginID)),
	pw = RTRIM(LTRIM(pw)),
	userName = RTRIM(LTRIM(userName))