SELECT E.name AS Employee 
FROM Employee AS M  INNER JOIN Employee AS E ON M.id = E.managerId -- M == manager | E == employee
WHERE M.salary < E.salary 
