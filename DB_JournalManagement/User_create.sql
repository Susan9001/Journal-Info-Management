CREATE TABLE [dbo].[Userr]
(
	[userr_id] VARCHAR(20) NOT NULL PRIMARY KEY,
	[userr_password] VARCHAR(50) NOT NULL CHECK(LEN(userr_password) > 6)
)
