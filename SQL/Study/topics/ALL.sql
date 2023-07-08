

SELECT ALL department FROM University;
this query is as similar as SELECT department FROM University;

it will return all the departments including repeated departments in the column.




Lets say i want to display the products where the products price will be less than all the products of Electornic. 
Then the query will be;


SELECT name
FROM products
WHERE price < ALL (SELECT price FROM products WHERE category = 'Electronics');

There can be alternative solution : 
WITH CTE AS (
    SELECT * FROM Products WHERE category = 'Electronics'
)SELECT * Products WHERE category NOT IN('Electronics') ................ etc 

Which is a mess!










More On ALL :




In MySQL, the "ALL" keyword is used in combination with comparison operators to specify that a condition must be true for all values in a subquery or a set of values. It is typically used in conjunction with the "IN" or "ANY" keywords.

Here's an example of using "ALL" in MySQL:


Using "ALL" with the "=" operator:

SELECT name
FROM employees
WHERE salary = ALL (SELECT salary FROM employees WHERE department = 'IT');

This query retrieves the names of employees whose salary is equal to the highest salary among all employees in the IT department.


Using "ALL" with the ">" operator:

SELECT name
FROM products
WHERE price > ALL (SELECT price FROM products WHERE category = 'Electronics');


This query retrieves the names of products whose price is greater than all prices of products in the Electronics category.

Using "ALL" with the "IN" operator:

SELECT name
FROM customers
WHERE id IN (SELECT customer_id FROM orders WHERE amount > ALL (SELECT amount FROM orders WHERE status = 'completed'));
