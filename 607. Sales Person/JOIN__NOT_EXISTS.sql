WITH Get_sales_id_with_RED AS (
    SELECT DISTINCT O.sales_id AS sales_id
    FROM Orders O
    JOIN Company C
        ON C.com_id = O.com_id
       AND C.name = 'RED'
)

SELECT SP.name
FROM SalesPerson SP
WHERE NOT EXISTS (
    SELECT sales_id
    FROM Get_sales_id_with_RED AS R
    WHERE R.sales_id = SP.sales_id
);
