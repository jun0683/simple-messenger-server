/****** Object:  ForeignKey [FK_chattingMessage_chattingRoom]    Script Date: 04/24/2012 00:50:48 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage] DROP CONSTRAINT [FK_chattingMessage_chattingRoom]
GO
/****** Object:  ForeignKey [FK_chattingMessage_userInfo]    Script Date: 04/24/2012 00:50:48 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage] DROP CONSTRAINT [FK_chattingMessage_userInfo]
GO
/****** Object:  ForeignKey [FK_chattingRoom_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoom_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoom]'))
ALTER TABLE [dbo].[chattingRoom] DROP CONSTRAINT [FK_chattingRoom_userInfo]
GO
/****** Object:  ForeignKey [FK_chattingRoomState_chattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState] DROP CONSTRAINT [FK_chattingRoomState_chattingRoom]
GO
/****** Object:  ForeignKey [FK_chattingRoomState_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState] DROP CONSTRAINT [FK_chattingRoomState_userInfo]
GO
/****** Object:  ForeignKey [FK_addFriendRequest_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest] DROP CONSTRAINT [FK_addFriendRequest_userInfo]
GO
/****** Object:  ForeignKey [FK_addFriendRequest_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest] DROP CONSTRAINT [FK_addFriendRequest_userInfo1]
GO
/****** Object:  ForeignKey [FK_message_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message] DROP CONSTRAINT [FK_message_userInfo]
GO
/****** Object:  ForeignKey [FK_message_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message] DROP CONSTRAINT [FK_message_userInfo1]
GO
/****** Object:  ForeignKey [FK_userFriends_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends] DROP CONSTRAINT [FK_userFriends_userInfo]
GO
/****** Object:  ForeignKey [FK_userFriends_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends] DROP CONSTRAINT [FK_userFriends_userInfo1]
GO
/****** Object:  ForeignKey [FK_userLog_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userLog_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userLog]'))
ALTER TABLE [dbo].[userLog] DROP CONSTRAINT [FK_userLog_userInfo]
GO
/****** Object:  StoredProcedure [dbo].[insertLog]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[insertLog]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[insertLog]
GO
/****** Object:  StoredProcedure [dbo].[isUserLogin]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[isUserLogin]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[isUserLogin]
GO
/****** Object:  StoredProcedure [dbo].[didFriendsRequest]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[didFriendsRequest]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[didFriendsRequest]
GO
/****** Object:  StoredProcedure [dbo].[updateFriendRequestState]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[updateFriendRequestState]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[updateFriendRequestState]
GO
/****** Object:  StoredProcedure [dbo].[delFriendRequest]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[delFriendRequest]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[delFriendRequest]
GO
/****** Object:  StoredProcedure [dbo].[getUserInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[getUserInfo]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[getUserInfo]
GO
/****** Object:  StoredProcedure [dbo].[getUserID]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[getUserID]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[getUserID]
GO
/****** Object:  StoredProcedure [dbo].[findUser]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[findUser]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[findUser]
GO
/****** Object:  StoredProcedure [dbo].[changeUserInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[changeUserInfo]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[changeUserInfo]
GO
/****** Object:  StoredProcedure [dbo].[isValidUser]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[isValidUser]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[isValidUser]
GO
/****** Object:  StoredProcedure [dbo].[registerNewUser]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[registerNewUser]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[registerNewUser]
GO
/****** Object:  StoredProcedure [dbo].[addFriendRequest]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[addFriendRequest]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[addFriendRequest]
GO
/****** Object:  StoredProcedure [dbo].[sendChattingMessage]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sendChattingMessage]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[sendChattingMessage]
GO
/****** Object:  StoredProcedure [dbo].[delFriend]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[delFriend]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[delFriend]
GO
/****** Object:  StoredProcedure [dbo].[addFriend]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[addFriend]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[addFriend]
GO
/****** Object:  StoredProcedure [dbo].[friends]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[friends]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[friends]
GO
/****** Object:  StoredProcedure [dbo].[withdrawUser]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[withdrawUser]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[withdrawUser]
GO
/****** Object:  StoredProcedure [dbo].[makeChattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[makeChattingRoom]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[makeChattingRoom]
GO
/****** Object:  StoredProcedure [dbo].[deliveredMessage]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[deliveredMessage]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[deliveredMessage]
GO
/****** Object:  StoredProcedure [dbo].[sendMessage]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sendMessage]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[sendMessage]
GO
/****** Object:  Table [dbo].[userLog]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userLog]') AND type in (N'U'))
DROP TABLE [dbo].[userLog]
GO
/****** Object:  Table [dbo].[message]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[message]') AND type in (N'U'))
DROP TABLE [dbo].[message]
GO
/****** Object:  Table [dbo].[friendRequest]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[friendRequest]') AND type in (N'U'))
DROP TABLE [dbo].[friendRequest]
GO
/****** Object:  Table [dbo].[userFriends]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userFriends]') AND type in (N'U'))
DROP TABLE [dbo].[userFriends]
GO
/****** Object:  Table [dbo].[chattingMessage]    Script Date: 04/24/2012 00:50:48 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingMessage]') AND type in (N'U'))
DROP TABLE [dbo].[chattingMessage]
GO
/****** Object:  Table [dbo].[chattingRoomState]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingRoomState]') AND type in (N'U'))
DROP TABLE [dbo].[chattingRoomState]
GO
/****** Object:  Table [dbo].[chattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingRoom]') AND type in (N'U'))
DROP TABLE [dbo].[chattingRoom]
GO
/****** Object:  StoredProcedure [dbo].[insertChattingRoomState]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[insertChattingRoomState]') AND type in (N'P', N'PC'))
DROP PROCEDURE [dbo].[insertChattingRoomState]
GO
/****** Object:  Table [dbo].[userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userInfo]') AND type in (N'U'))
DROP TABLE [dbo].[userInfo]
GO
/****** Object:  Table [dbo].[DB_EXAMPLE]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DB_EXAMPLE]') AND type in (N'U'))
DROP TABLE [dbo].[DB_EXAMPLE]
GO
/****** Object:  Default [DF_addFriendRequest_request]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.default_constraints WHERE object_id = OBJECT_ID(N'[dbo].[DF_addFriendRequest_request]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
Begin
IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF_addFriendRequest_request]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[friendRequest] DROP CONSTRAINT [DF_addFriendRequest_request]
END


End
GO
/****** Object:  Default [DF_message_delivery]    Script Date: 04/24/2012 00:50:49 ******/
IF  EXISTS (SELECT * FROM sys.default_constraints WHERE object_id = OBJECT_ID(N'[dbo].[DF_message_delivery]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
Begin
IF  EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF_message_delivery]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[message] DROP CONSTRAINT [DF_message_delivery]
END


End
GO
/****** Object:  Table [dbo].[DB_EXAMPLE]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DB_EXAMPLE]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[DB_EXAMPLE](
	[INT_VALUE] [int] NOT NULL,
	[STRING_VALUE] [varchar](50) COLLATE Korean_Wansung_CI_AS NULL,
	[DOUBLE_VALUE] [float] NULL,
	[EXAMPLE_LONG] [int] NULL,
	[EXAMPLE_DATE] [datetime] NULL
)
END
GO
/****** Object:  Table [dbo].[userInfo]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userInfo]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[userInfo](
	[userID] [int] IDENTITY(1,1) NOT NULL,
	[loginID] [varchar](50) COLLATE Korean_Wansung_CI_AS NOT NULL,
	[pw] [varchar](50) COLLATE Korean_Wansung_CI_AS NOT NULL,
	[userName] [nvarchar](50) COLLATE Korean_Wansung_CI_AS NULL,
 CONSTRAINT [PK_userInfo] PRIMARY KEY CLUSTERED 
(
	[userID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
)
END
GO
IF NOT EXISTS (SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID(N'[dbo].[userInfo]') AND name = N'UK_loginID')
CREATE UNIQUE NONCLUSTERED INDEX [UK_loginID] ON [dbo].[userInfo] 
(
	[loginID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
GO
/****** Object:  StoredProcedure [dbo].[insertChattingRoomState]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[insertChattingRoomState]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[insertChattingRoomState]
	@chattingRoomNumber int,
	@userID int,
	@userState bit
as
	insert into chattingroomstate (chattingRoomNumber,userID,userState,stateTime)
	values (@chattingRoomNumber,@userID,@userState,GETDATE())
	
' 
END
GO
/****** Object:  Table [dbo].[chattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingRoom]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[chattingRoom](
	[roomNumber] [int] IDENTITY(1,1) NOT NULL,
	[createUserID] [int] NOT NULL,
	[createTime] [datetime] NOT NULL,
 CONSTRAINT [PK_chattingRoom] PRIMARY KEY CLUSTERED 
(
	[roomNumber] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
)
END
GO
/****** Object:  Table [dbo].[chattingRoomState]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingRoomState]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[chattingRoomState](
	[chattingRoomNumber] [int] NOT NULL,
	[userID] [int] NOT NULL,
	[userState] [bit] NOT NULL,
	[stateTime] [datetime] NOT NULL
)
END
GO
/****** Object:  Table [dbo].[chattingMessage]    Script Date: 04/24/2012 00:50:48 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[chattingMessage]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[chattingMessage](
	[chattingRoomNumber] [int] NOT NULL,
	[sendUserID] [int] NOT NULL,
	[chattingMessage] [nvarchar](max) COLLATE Korean_Wansung_CI_AS NOT NULL,
	[messageTime] [datetime] NOT NULL
)
END
GO
/****** Object:  Table [dbo].[userFriends]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userFriends]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[userFriends](
	[userID] [int] NOT NULL,
	[userFriend] [int] NOT NULL
)
END
GO
IF NOT EXISTS (SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID(N'[dbo].[userFriends]') AND name = N'UK_userFriends')
CREATE UNIQUE NONCLUSTERED INDEX [UK_userFriends] ON [dbo].[userFriends] 
(
	[userID] ASC,
	[userFriend] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
GO
/****** Object:  Table [dbo].[friendRequest]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[friendRequest]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[friendRequest](
	[userID] [int] NOT NULL,
	[friendID] [int] NOT NULL,
	[request] [bit] NOT NULL
)
END
GO
/****** Object:  Table [dbo].[message]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[message]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[message](
	[messageID] [int] IDENTITY(1,1) NOT NULL,
	[fromUserID] [int] NOT NULL,
	[toUserID] [int] NOT NULL,
	[message] [nvarchar](1024) COLLATE Korean_Wansung_CI_AS NOT NULL,
	[delivery] [bit] NOT NULL,
 CONSTRAINT [PK_message] PRIMARY KEY CLUSTERED 
(
	[messageID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
)
END
GO
/****** Object:  Table [dbo].[userLog]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[userLog]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[userLog](
	[userID] [int] NOT NULL,
	[logTime] [datetime] NOT NULL,
	[logState] [bit] NOT NULL
)
END
GO
IF NOT EXISTS (SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID(N'[dbo].[userLog]') AND name = N'IX_userLog')
CREATE UNIQUE NONCLUSTERED INDEX [IX_userLog] ON [dbo].[userLog] 
(
	[logTime] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON)
GO
/****** Object:  StoredProcedure [dbo].[sendMessage]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sendMessage]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'
CREATE proc [dbo].[sendMessage]
	@fromUserID	int,
	@toUserID	int,
	@message	nvarchar(1024)
as
begin
	
	IF exists(select * from userInfo where userID = @toUserID or userID = @fromUserID)
		BEGIN
		INSERT INTO message(fromUserID,toUserID,message)
	     VALUES(@fromUserID,@toUserID,@message)
		
		return 1
		END
	ELSE
		return 0
end



' 
END
GO
/****** Object:  StoredProcedure [dbo].[deliveredMessage]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[deliveredMessage]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'
CREATE proc [dbo].[deliveredMessage]
	@messageID	int
as
begin
	
	IF exists(select * from message where messageID = @messageID)
		BEGIN
		UPDATE message
		SET delivery = 1
		WHERE messageID = @messageID
		return 1
		END
	ELSE
		return 0
end




' 
END
GO
/****** Object:  StoredProcedure [dbo].[makeChattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[makeChattingRoom]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[makeChattingRoom]
	@userID int
AS
	INSERT INTO chattingroom(createUserID,createTime)
	VALUES (@userID,GETDATE())
	return @@IDENTITY;
' 
END
GO
/****** Object:  StoredProcedure [dbo].[withdrawUser]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[withdrawUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE PROCEDURE [dbo].[withdrawUser]
(
	@loginID	varchar(50),
	@pw			varchar(50)
)
AS
	DECLARE @userID INT
	set @userID = (select userID from userInfo where loginID = @loginID and pw = @pw)
	IF @userID IS NULL
		return 0;
	ELSE
		BEGIN
		DELETE FROM userLog WHERE userID = @userID;
		DELETE FROM chattingRoomState WHERE userID = @userID;
		DELETE FROM chattingMessage WHERE sendUserID = @userID;
		DELETE FROM chattingRoom WHERE createUserID = @userID;
		DELETE FROM userFriends WHERE userID = @userID or userFriend = @userID;
		DELETE FROM userInfo WHERE userID = @userID;

		return 1;
		END' 
END
GO
/****** Object:  StoredProcedure [dbo].[friends]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[friends]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'create proc [dbo].[friends]
@userID int
as
select f.userfriend, u.loginid, u.pw, u.username
from userFriends f inner join userInfo u
	on f.userfriend = u.userid
where f.userid = @userID' 
END
GO
/****** Object:  StoredProcedure [dbo].[addFriend]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[addFriend]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[addFriend]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	
	IF exists(select userID from userFriends where userFriend = @friendID and userID = @userID)
		BEGIN
		return 0
		END
	ELSE
		BEGIN
		INSERT userFriends
		values (@userID,@friendID)
		return 1
		END

END













' 
END
GO
/****** Object:  StoredProcedure [dbo].[delFriend]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[delFriend]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[delFriend]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	
	IF exists(select userID from userFriends where userFriend = @friendID and userID = @userID)
		BEGIN
		DELETE FROM userFriends
		WHERE userFriend = @friendID and userID = @userID
		return 1
		END
	ELSE
		return 0


END












' 
END
GO
/****** Object:  StoredProcedure [dbo].[sendChattingMessage]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[sendChattingMessage]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'create proc [dbo].[sendChattingMessage]
	@chattingRoomNumber int,
	@sendUserID int,
	@message	nvarchar(max)
as
	insert into chattingMessage (chattingRoomNumber,sendUserID,chattingMessage,messageTime)
	values (@chattingRoomNumber,@sendUserID,@message,GETDATE())' 
END
GO
/****** Object:  StoredProcedure [dbo].[addFriendRequest]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[addFriendRequest]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[addFriendRequest]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	IF (exists(select userID from userInfo where userID = @userID) and exists(select userID from userInfo where userID = @friendID))
		BEGIN
		IF not exists(select * from friendRequest where userID = @userID and friendID = @friendID)
			BEGIN
			INSERT INTO friendRequest(userID,friendID,request)
			VALUES (@userID,@friendID,1)	
			return 1
			END
		END
	ELSE
		return 0
	
END



' 
END
GO
/****** Object:  StoredProcedure [dbo].[registerNewUser]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[registerNewUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'
CREATE proc [dbo].[registerNewUser]
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

' 
END
GO
/****** Object:  StoredProcedure [dbo].[isValidUser]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[isValidUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'create proc [dbo].[isValidUser]
(
	@loginID	varchar(50)
)
AS
	IF exists(select loginID from userInfo where loginID = @loginID)
		return 1;
	ELSE
		return 0;
' 
END
GO
/****** Object:  StoredProcedure [dbo].[changeUserInfo]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[changeUserInfo]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'create proc [dbo].[changeUserInfo]
(
	@loginID	varchar(50),
	@pw			varchar(50),	
	@userName		nvarchar(50)
)
AS
	IF exists(select loginID from userInfo where loginID = @loginID)
		BEGIN
		UPDATE userInfo
		SET pw = @pw,userName = @userName
		WHERE loginID = @loginID
		return 1;
		END
	ELSE
		return 0;


' 
END
GO
/****** Object:  StoredProcedure [dbo].[findUser]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[findUser]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[findUser]
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
END' 
END
GO
/****** Object:  StoredProcedure [dbo].[getUserID]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[getUserID]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'create proc [dbo].[getUserID]
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
	
END' 
END
GO
/****** Object:  StoredProcedure [dbo].[getUserInfo]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[getUserInfo]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[getUserInfo]
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
	
END' 
END
GO
/****** Object:  StoredProcedure [dbo].[delFriendRequest]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[delFriendRequest]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[delFriendRequest]
(
	@userID int,
	@friendID int
)
AS
BEGIN
	IF exists(select * from friendRequest where friendID = @friendID and userid = @userid)
		BEGIN
		DELETE FROM friendRequest
		WHERE friendID = @friendID and userid = @userid
		return 1
		END
	ELSE
		BEGIN
		return 0
		END
END



' 
END
GO
/****** Object:  StoredProcedure [dbo].[updateFriendRequestState]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[updateFriendRequestState]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[updateFriendRequestState]
(
	@userID int,
	@friendID int,
	@respond int
)
AS
BEGIN
	IF (EXISTS(select * from friendRequest WHERE friendID = @friendID and userid = @userid ))
		BEGIN
		UPDATE friendRequest
		SET request = @respond
		WHERE friendID = @friendID and userid = @userid
		return 1
		END
	ELSE
		return 0
END







' 
END
GO
/****** Object:  StoredProcedure [dbo].[didFriendsRequest]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[didFriendsRequest]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[didFriendsRequest]
(
	@friendID int
)
AS
BEGIN
	
	SELECT	userID
	FROM	friendRequest
	WHERE	friendID = @friendID and request = 1
	
	IF exists(select userID from friendRequest where friendID = @friendID and request = 1)
		return 1
	ELSE
		return 0
	
END








' 
END
GO
/****** Object:  StoredProcedure [dbo].[isUserLogin]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[isUserLogin]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'
CREATE proc [dbo].[isUserLogin]
	@userID int
AS
	declare @state bit
	set @state = 0
	select @state = logstate
	from userlog
	where logtime = (select max(logtime)
						from userlog
						where userid = @userID)
	return @state
' 
END
GO
/****** Object:  StoredProcedure [dbo].[insertLog]    Script Date: 04/24/2012 00:50:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[insertLog]') AND type in (N'P', N'PC'))
BEGIN
EXEC dbo.sp_executesql @statement = N'CREATE proc [dbo].[insertLog]
(
	@userID int,
	@logState bit,
	@logresult bit OUTPUT
)
AS
BEGIN
	declare @state bit

	exec @state = isUserLogin @userID

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




' 
END
GO
/****** Object:  Default [DF_addFriendRequest_request]    Script Date: 04/24/2012 00:50:49 ******/
IF Not EXISTS (SELECT * FROM sys.default_constraints WHERE object_id = OBJECT_ID(N'[dbo].[DF_addFriendRequest_request]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
Begin
IF NOT EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF_addFriendRequest_request]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[friendRequest] ADD  CONSTRAINT [DF_addFriendRequest_request]  DEFAULT ((0)) FOR [request]
END


End
GO
/****** Object:  Default [DF_message_delivery]    Script Date: 04/24/2012 00:50:49 ******/
IF Not EXISTS (SELECT * FROM sys.default_constraints WHERE object_id = OBJECT_ID(N'[dbo].[DF_message_delivery]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
Begin
IF NOT EXISTS (SELECT * FROM dbo.sysobjects WHERE id = OBJECT_ID(N'[DF_message_delivery]') AND type = 'D')
BEGIN
ALTER TABLE [dbo].[message] ADD  CONSTRAINT [DF_message_delivery]  DEFAULT ((0)) FOR [delivery]
END


End
GO
/****** Object:  ForeignKey [FK_chattingMessage_chattingRoom]    Script Date: 04/24/2012 00:50:48 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage]  WITH CHECK ADD  CONSTRAINT [FK_chattingMessage_chattingRoom] FOREIGN KEY([chattingRoomNumber])
REFERENCES [dbo].[chattingRoom] ([roomNumber])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage] CHECK CONSTRAINT [FK_chattingMessage_chattingRoom]
GO
/****** Object:  ForeignKey [FK_chattingMessage_userInfo]    Script Date: 04/24/2012 00:50:48 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage]  WITH CHECK ADD  CONSTRAINT [FK_chattingMessage_userInfo] FOREIGN KEY([sendUserID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingMessage_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingMessage]'))
ALTER TABLE [dbo].[chattingMessage] CHECK CONSTRAINT [FK_chattingMessage_userInfo]
GO
/****** Object:  ForeignKey [FK_chattingRoom_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoom_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoom]'))
ALTER TABLE [dbo].[chattingRoom]  WITH CHECK ADD  CONSTRAINT [FK_chattingRoom_userInfo] FOREIGN KEY([createUserID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoom_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoom]'))
ALTER TABLE [dbo].[chattingRoom] CHECK CONSTRAINT [FK_chattingRoom_userInfo]
GO
/****** Object:  ForeignKey [FK_chattingRoomState_chattingRoom]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState]  WITH CHECK ADD  CONSTRAINT [FK_chattingRoomState_chattingRoom] FOREIGN KEY([chattingRoomNumber])
REFERENCES [dbo].[chattingRoom] ([roomNumber])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_chattingRoom]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState] CHECK CONSTRAINT [FK_chattingRoomState_chattingRoom]
GO
/****** Object:  ForeignKey [FK_chattingRoomState_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState]  WITH CHECK ADD  CONSTRAINT [FK_chattingRoomState_userInfo] FOREIGN KEY([userID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_chattingRoomState_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[chattingRoomState]'))
ALTER TABLE [dbo].[chattingRoomState] CHECK CONSTRAINT [FK_chattingRoomState_userInfo]
GO
/****** Object:  ForeignKey [FK_addFriendRequest_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest]  WITH CHECK ADD  CONSTRAINT [FK_addFriendRequest_userInfo] FOREIGN KEY([userID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest] CHECK CONSTRAINT [FK_addFriendRequest_userInfo]
GO
/****** Object:  ForeignKey [FK_addFriendRequest_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest]  WITH CHECK ADD  CONSTRAINT [FK_addFriendRequest_userInfo1] FOREIGN KEY([friendID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_addFriendRequest_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[friendRequest]'))
ALTER TABLE [dbo].[friendRequest] CHECK CONSTRAINT [FK_addFriendRequest_userInfo1]
GO
/****** Object:  ForeignKey [FK_message_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message]  WITH CHECK ADD  CONSTRAINT [FK_message_userInfo] FOREIGN KEY([fromUserID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message] CHECK CONSTRAINT [FK_message_userInfo]
GO
/****** Object:  ForeignKey [FK_message_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message]  WITH CHECK ADD  CONSTRAINT [FK_message_userInfo1] FOREIGN KEY([toUserID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_message_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[message]'))
ALTER TABLE [dbo].[message] CHECK CONSTRAINT [FK_message_userInfo1]
GO
/****** Object:  ForeignKey [FK_userFriends_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends]  WITH CHECK ADD  CONSTRAINT [FK_userFriends_userInfo] FOREIGN KEY([userID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends] CHECK CONSTRAINT [FK_userFriends_userInfo]
GO
/****** Object:  ForeignKey [FK_userFriends_userInfo1]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends]  WITH CHECK ADD  CONSTRAINT [FK_userFriends_userInfo1] FOREIGN KEY([userFriend])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userFriends_userInfo1]') AND parent_object_id = OBJECT_ID(N'[dbo].[userFriends]'))
ALTER TABLE [dbo].[userFriends] CHECK CONSTRAINT [FK_userFriends_userInfo1]
GO
/****** Object:  ForeignKey [FK_userLog_userInfo]    Script Date: 04/24/2012 00:50:49 ******/
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userLog_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userLog]'))
ALTER TABLE [dbo].[userLog]  WITH CHECK ADD  CONSTRAINT [FK_userLog_userInfo] FOREIGN KEY([userID])
REFERENCES [dbo].[userInfo] ([userID])
GO
IF  EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_userLog_userInfo]') AND parent_object_id = OBJECT_ID(N'[dbo].[userLog]'))
ALTER TABLE [dbo].[userLog] CHECK CONSTRAINT [FK_userLog_userInfo]
GO
