CREATE VIEW [dbo].[V_Contributor]
AS
SELECT U.unit_id, U.unit_name, Con.contributor_id, Con.contributor_name, J.journal_name, COUNT(*) contribute_sum  
FROM Unit AS U LEFT OUTER JOIN Contributor AS Con  
ON U.unit_id = Con.unit_id  
LEFT OUTER JOIN Paper AS P  
ON Con.contributor_id = P.contributor_id  
JOIN Journal AS J  
ON P.journal_id = J.journal_id  
GROUP BY U.unit_id, U.unit_name, Con.contributor_id, Con.contributor_name, J.journal_name;  
--WITH CHECK OPTION
--ORDER BY J.journal_id;
