# Write your MySQL query statement below
DELETE pl FROM Person pl JOIN Person p2 on pl.email=p2.email AND pl.id>p2.id;