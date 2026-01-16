SELECT C.name AS customers
FROM Customers AS C LEFT JOIN Orders AS O ON O.customerId = C.id
WHERE customerid IS NULL
