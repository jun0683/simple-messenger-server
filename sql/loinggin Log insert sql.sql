INSERT INTO [messenger].[dbo].[logginLog]
           ([userID]
           ,[logginTime]
           ,[logginState])
     VALUES
           (9
           ,GETDATE()
           ,0)