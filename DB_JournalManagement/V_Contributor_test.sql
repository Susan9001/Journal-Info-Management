SELECT *
FROM V_Contributor_Journal
WHERE unit_id IS NULL

--INSERT INTO Contributor(contributor_id, contributor_name, contributor_email, contributor_phone, unit_id)
--VALUES (11, 'Churchill', 'theWar@66.cm', '93884834', Null);

--SELECT C.*, CV.contribute_sum
--FROM V_Contributor CV, Contributor C
--WHERE CV.contributor_id = C.contributor_id

--UPDATE Contributor
--SET unit_id = 1
--WHERE contributor_id = 9

--SELECT unit_id
--FROM Unit
--WHERE unit_name = '自由投稿人'