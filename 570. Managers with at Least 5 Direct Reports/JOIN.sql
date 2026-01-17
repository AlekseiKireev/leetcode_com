-- Write your PostgreSQL query statement below

WITH M_IDS AS (
    SELECT managerId FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(managerId) >=5
)

SELECT name  FROM Employee AS E INNER JOIN M_IDS ON E.id = M_IDS.managerId
