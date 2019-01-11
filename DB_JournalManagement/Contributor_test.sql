--SELECT unit_id, unit_name FROM Unit ORDER BY unit_id; 

SELECT U.unit_id, U.unit_name, Con.contributor_id, Con.contributor_name, J.journal_name, COUNT(*) AS '总投稿数'
FROM Unit AS U LEFT OUTER JOIN Contributor AS Con
ON U.unit_id = Con.unit_id
AND Con.contributor_id IN (1, 2, 3)
LEFT OUTER JOIN Paper AS P
ON Con.contributor_id = P.contributor_id
JOIN Journal AS J
ON P.journal_id = J.journal_id
WHERE U.unit_id = -1
GROUP BY U.unit_id, U.unit_name, Con.contributor_id, Con.contributor_name, J.journal_name;
GO
