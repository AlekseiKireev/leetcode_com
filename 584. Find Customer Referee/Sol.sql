-- Write your PostgreSQL query statement below

SELECT name 
FROM Customer AS C
WHERE C.referee_id !=2 OR C.referee_id IS NULL
