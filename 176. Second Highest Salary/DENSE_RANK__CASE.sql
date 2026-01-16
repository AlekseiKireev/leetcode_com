WITH HighestSalary AS (
    SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS d_rnk
    FROM Employee
)
SELECT
    CASE
        WHEN MAX(d_rnk) < 2 THEN NULL
        ELSE (SELECT salary FROM HighestSalary WHERE d_rnk = 2 LIMIT 1)
    END AS SecondHighestSalary
FROM HighestSalary;
