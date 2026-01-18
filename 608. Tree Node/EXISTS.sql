-- Write your PostgreSQL query statement below

SELECT T.id,
    CASE 
        WHEN T.p_id IS NULL THEN 'Root'
        WHEN NOT EXISTS (
                    SELECT id FROM Tree AS Other_T WHERE T.id=Other_T.p_id
                ) THEN 'Leaf'
        ELSE 'Inner'

        END AS type  

FROM Tree AS T
