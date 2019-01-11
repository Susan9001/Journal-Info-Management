CREATE TABLE [dbo].[Editor] (
    editor_id	INT	NOT NULL	PRIMARY KEY	IDENTITY(1, 1),
	editor_name	NVARCHAR(20)	NOT NULL,
	editor_email	VARCHAR(40)	NOT NULL,
	editor_phone	VARCHAR(15),
	publisher_id	INT NOT NULL,
	CONSTRAINT FK_editor_publisherId FOREIGN KEY (publisher_id) REFERENCES Publisher(publisher_id) ON DELETE CASCADE
);