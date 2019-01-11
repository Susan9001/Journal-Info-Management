--测试publisher的种种语句

SELECT publisher_id, publisher_name, COUNT(*)
FROM Publisher
WHERE publisher_id = 2
OR publisher_name = '广州出版社'
GROUP BY publisher_id, publisher_name;

--SELECT MAX(publisher_id) max_publisher_id
--FROM Publisher

--UPDATE Publisher 
--SET publisher_name = N'广州出版社', 
--	publisher_email = 'CCW@163.com' 
--WHERE publisher_name = N'羊城出版社';
