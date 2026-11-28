# Write your MySQL query statement below
SELECT email as Email from Person GROUP BY email having count(email)>1;