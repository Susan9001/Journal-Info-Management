INSERT INTO Journal(journal_id, journal_name, new_publish_date, editor_id, typee_id)
VALUES ('0001', '中国社会科学', GETDATE(), 1, 'K'),
		('0002', '哲学研究', Null, 2, 'B1'),
		('0003', '心理学报', GETDATE(),3, 'B1'),
		('0004', '经济研究', Null, 4, 'F'),
		('0005', '经济学动态', Null, 5, 'F'),
		('0006', '经济学家', Null, Null, 'F'),
		('0007', '世界经济', Null, Null, 'F1');
