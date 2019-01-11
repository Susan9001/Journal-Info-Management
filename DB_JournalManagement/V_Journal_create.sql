CREATE VIEW V_Journal
AS
SELECT J.journal_id, J.journal_name, T.typee_name, P.publisher_name, E.editor_name, J.new_publish_date  
FROM Journal AS J, Editor AS E, Publisher AS P, Typee AS T  
WHERE J.editor_id = E.editor_id  
AND E.publisher_id = P.publisher_id  
AND J.typee_id = T.typee_id  
--ORDER BY J.journal_id; 