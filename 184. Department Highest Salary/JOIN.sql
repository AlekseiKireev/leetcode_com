-- Write your PostgreSQL query statement below

WITH MaxSalaryOnDep AS (
    SELECT E.departmentId AS depID, MAX(E.Salary) AS max_salary
    FROM Employee AS E 
    GROUP BY E.departmentId
)

SELECT D.name AS Department , E.name AS Employee , E.Salary
FROM Employee AS E 
    INNER JOIN Department AS D ON E.departmentId = D.id 
    INNER JOIN MaxSalaryOnDep AS MS ON MS.depID = D.id AND MS.max_salary = E.Salary
