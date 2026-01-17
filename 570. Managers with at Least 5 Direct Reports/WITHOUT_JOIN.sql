-- Write your PostgreSQL query statement below

WITH M_IDS AS (SELECT managerId FROM Employee 
GROUP BY managerId 
HAVING COUNT(managerId) >=5)

SELECT name  FROM Employee AS E
WHERE E.id IN (SELECT managerId FROM M_IDS)
