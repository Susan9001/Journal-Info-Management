SELECT *
FROM V_Journal
WHERE journal_id = -1
OR (typee_name LIKE '%综合性人文;社会科学%'
)

--SELECT catalog_name
--FROM Catalogg
--ORDER BY catalog_id

--SELECT * FROM V_Journal;

--SELECT J.journal_id, J.journal_name, J.new_publish_date, C.catalog_name, T.typee_name, E.editor_name, E.editor_email  
--FROM Journal AS J, Editor AS E, Typee AS T, Catalogg AS C  
--WHERE journal_id = 3  
--AND J.editor_id = E.editor_id  
--AND J.typee_id = T.typee_id  
--AND T.catalog_id = C.catalog_id; 
