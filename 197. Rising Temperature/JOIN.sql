-- Write your PostgreSQL query statement below

SELECT MainData.id
FROM Weather AS MainData
JOIN Weather AS OtherData
  ON MainData.recordDate - OtherData.recordDate = 1 
  AND MainData.temperature  > OtherData.temperature  
