WITH UniqIdx AS (
    SELECT email, MIN(id) AS id
    FROM Person
    GROUP BY email
)

DELETE FROM Person AS P
USING UniqIdx AS UI
WHERE P.email = UI.email AND P.id <> UI.id
