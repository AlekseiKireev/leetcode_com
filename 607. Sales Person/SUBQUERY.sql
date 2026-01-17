-- Write your PostgreSQL query statement below

WITH Get_sales_id_with_RED AS(

SELECT O.sales_id AS RED_sales_id FROM Orders AS O WHERE O.com_id IN(
    SELECT C.com_id FROM Company  AS C WHERE C.name = 'RED'
)

)

SELECT SP.name FROM SalesPerson AS SP WHERE SP.sales_id NOT IN (
    SELECT GET_RED.RED_sales_id FROM Get_sales_id_with_RED AS GET_RED
)
