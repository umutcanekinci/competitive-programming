# Write your MySQL query statement below
#SELECT p1.email FROM Person AS p1, Person AS p2 WHERE p1.email = p2.email AND p1.id != p2.id 

SELECT email FROM Person GROUP BY email HAVING COUNT(email) > 1