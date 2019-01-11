CREATE VIEW [dbo].[V_Paper]
AS 
SELECT P.paper_id, P.paper_name, P.contributor_id, Con.contributor_name, P.journal_id, J.journal_name, P.paper_publisher_date 
FROM Paper P, Journal J, Contributor Con
WHERE P.journal_id = J.journal_id
AND P.contributor_id = Con.contributor_id
