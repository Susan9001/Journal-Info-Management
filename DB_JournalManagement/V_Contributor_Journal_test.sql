-- SELECT contributor_id, contributor_name 
--FROM Contributor 
--WHERE unit_id IS NULL; 

SELECT * 
FROM V_Contributor
ORDER BY CASE 
	WHEN unit_id IS NULL THEN 1 ELSE 0 END ASC,
	contributor_id ASC
