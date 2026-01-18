-- Write your PostgreSQL query statement below

SELECT T.id,
    CASE 
        WHEN T.p_id IS NULL THEN 'Root'
        WHEN T.id NOT IN (
            SELECT DISTINCT(Other_T.p_id) FROM Tree AS Other_T WHERE Other_T.p_id IS NOT NULL
        ) THEN 'Leaf'
        ELSE 'Inner'
        END AS type  

FROM Tree AS T
