CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    
WITH HighestSalary AS (
    SELECT
        E.salary,
        DENSE_RANK() OVER (ORDER BY E.salary DESC) AS d_rnk
    FROM Employee AS E
)
SELECT
    CASE
        WHEN MAX(d_rnk) < N THEN NULL
        ELSE (SELECT HS.salary FROM HighestSalary AS HS WHERE d_rnk = N LIMIT 1)
    END 
FROM HighestSalary

  );
END;
$$ LANGUAGE plpgsql;
