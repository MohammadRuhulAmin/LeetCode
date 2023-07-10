SELECT id FROM Products 
INTERSECT 
SELECT id FROM Customers;
THis is invalid in mysql.However we can achieve the same output by 
the following query : 


SELECT id FROM Products WHERE id IN (
    SELECT id FROM Customers
);



SELECT id FROM Products 
EXCEPT
SELECT id FROM Products.

is not valid but the same query is  : 

SELECT id FROM Products WHERE id NOT IN (
    SELECT id FROM Products
);
