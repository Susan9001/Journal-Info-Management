CREATE TABLE [dbo].[Journal] (
    journal_id		VARCHAR(6)		NOT NULL	PRIMARY KEY,
	journal_name	NVARCHAR(50)	NOT NULL,
	new_publish_date	DATE,
	editor_id		INT,
	typee_id		VARCHAR(30)		NOT NULL,
	CONSTRAINT FK_journal_editorId FOREIGN KEY (editor_id) REFERENCES Editor(editor_id) ON DELETE SET NULL,
	CONSTRAINT FK_journal_typeeId FOREIGN KEY (typee_id) REFERENCES Typee(typee_id) ON DELETE CASCADE
);