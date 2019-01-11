SELECT catalog_name 
FROM Catalogg
ORDER BY catalog_id;

--SELECT typee_id, typee_name 
--FROM Typee
--WHERE catalog_id IN
--(
--	SELECT catalog_id
--	FROM Catalogg
--	WHERE catalog_name = '第二编 经济'
--);

---- 设置catalog_name的索引
--CREATE INDEX catalog_id ON Typee(catalog_name);
