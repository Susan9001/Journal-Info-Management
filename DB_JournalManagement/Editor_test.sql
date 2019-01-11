SELECT editor_name
FROM Editor
WHERE editor_name LIKE '%蓝%' 
OR editor_name LIKE '%魏%';

--SELECT E.*, P.publisher_name
--FROM Editor AS E, Publisher AS P
--WHERE editor_id = 2
--AND E.publisher_id = P.publisher_id