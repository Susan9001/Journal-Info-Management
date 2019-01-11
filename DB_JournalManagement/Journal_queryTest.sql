-- 查询每一Typee类的期刊数
SELECT C.catalog_id, C.catalog_name, T.typee_id, T.typee_name, COUNT(J.journal_id) countJournal
FROM Catalogg C, Typee T, Journal J
WHERE C.catalog_id = T.catalog_id
	AND T.typee_id = J.typee_id
GROUP BY C.catalog_id, C.catalog_name, T.typee_id, T.typee_name


--SELECT MAX(journal_id) max_journal_id FROM Journal; 

--SELECT journal_id
--FROM Journal
--WHERE journal_name = '888'

--UPDATE Editor
--SET editor_email = 'chengnanWang@126.com'
--WHERE editor_id = 1

--UPDATE Journal
--SET journal_name = '世界宗教研究',
--	new_publish_date = '1997-12-7',
--	editor_id = 5,
--	typee_id = 'B9'
--WHERE journal_id = 6;

--SELECT editor_id
--FROM Editor
--WHERE editor_name = '王承南'

--SELECT typee_id
--FROM Typee
--WHERE typee_name = '哲学';

--SELECT DISTINCT typee_name
--FROM Typee
--WHERE catalog_name = '第二编  经济';

--SELECT DISTINCT catalog_name
--FROM Typee

--SELECT J.journal_id, J.journal_name, T.catalog_name, T.typee_name, E.editor_name, E.editor_email, J.new_publish_date
--FROM Journal AS J, Editor AS E, Publisher AS P, Typee AS T 
--WHERE j.journal_id = '0002'
--	AND J.editor_id = E.editor_id 
--	AND E.publisher_id = P.publisher_id 
--	AND J.typee_id = T.typee_id 
--ORDER BY J.journal_id;
