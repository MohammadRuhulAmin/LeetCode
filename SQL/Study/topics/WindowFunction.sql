
WHEN YOU are using window function you must use over() clause 
like LEAD() OVER(),LAG() OVER(),MAX() OVER() like this. 
Window function creates window (it creates a partition).Inside each of 
the partition we can again create some sub set of records which is called frame.
So we can say that, Frame is some subset of partitions.

Lets say you want to get the top 3 emploees who get the highest salary. Or lets say you want to display the maximum and minimum salary employee of each Department.
The Window Functions are RANK(),DENSE_RANK(),OVER(),LEAD(),LAG().

Definition : A window function performs an aggerate-like operation on a set of query rows.

OVER() :

    SELECT E.*,MAX(E.salary) OVER() AS 'MxSal'
    FROM Employee E;

    OVER Clause will create a new Column name as MxSal, and the highest salary will be displayed in each record!
    Here inside the OVER Clause there is no parameter, Max is an aggerate function. When the over clause place after Max function,
    it will be converted into window function.

    If we want to Get MxSal column as the highest salary according to the each department Then the query will be 

    SELECT E.*,MAX(E.salary) OVER(PARTITION BY department_name) AS 'MxSal'
    FROM Employee E;

    it will return the Group by department of highest salary 

ROW_NUMBER():

    SELECT E.*, ROW_NUMBER() OVER() AS 'RowNo'
    FROM Employees E 
    
    This query will return just a number. serial 1 to N 
    
    But if i want to Display the row number Group by department Name ? 
    Then the Query will be: 
    
    SELECT E.*, ROW NUMBER() OVER(PERTITION BY department_name) AS 'RowNo'
    FROM Employees E;

    If i want to sort the employees according to their employee_id then the query will be : 

    SELECT E.*, ROW_NUMBER() OVER(PERTITION BY department_name ORDER BY employee_id) AS 'RowNo'
    FROM Employees E; 

    -- FETCH the first 2 highest salary earn employees from each department 
    SELECT * FROM (
        SELECT E.*,
        ROW_NUMBER()OVER(PERTITION BY department_name ORDER BY employee_id) AS 'RowNo'
        FROM Employee E
    ) AS tbl 
    WHERE tbl.RowNo <3;

 ** PARTITION is used as GROUP BY in window function ~~~

LEAD LAG :

    LEAD(expression, offset, default) OVER (PARTITION BY ... ORDER BY ...)

    SELECT E.*,
    LAG(salary,2,0) OVER(PARTITION BY dept_name ORDER BY emp_id) AS 'prev',
    LEAD(salary,2,0) OVER(PARTITION BY dept_name ORDER BY emp_id) AS 'next'
    FROM Employee E; 

Let's break down each part of the syntax:

    expression: This is the column or expression from which you want to retrieve the subsequent value.
    offset: This specifies the number of rows ahead from the current row where you want to retrieve the value. In your case, the offset is 2, meaning you want to retrieve the value of the column two rows ahead.
    default: This is an optional parameter that specifies the value to return if there is no subsequent row available. If you don't provide a default value, it will return NULL by default.
    PARTITION BY: This is an optional clause that allows you to divide the rows into partitions based on one or more columns. If you omit this clause, the LEAD() function will consider the entire result set as a single partition.
    ORDER BY: This specifies the ordering of the rows within each partition. You can specify one or more columns to define the order.

Here's an example that demonstrates the usage of LEAD() function to retrieve the salary of the next row, two rows ahead, from a table called employees:

SELECT salary, LEAD(salary, 2, 0) OVER (ORDER BY employee_id) AS next_salary
FROM employees;

In this example, the salary column represents the current row's salary, and the LEAD(salary, 2, 0) expression retrieves the salary of the row that is two positions ahead. The OVER (ORDER BY employee_id) clause specifies that the ordering should be based on the employee_id column.

The result of the query will include the salary column and a new column called next_salary, which contains the salary of the row two positions ahead. If there is no subsequent row available, the next_salary column will have the default value specified (0 in this case).

Note: The LEAD() function is available in MySQL 8.0 and later versions. If you are using an older version of MySQL, the LEAD() function may not be available, and you would need to use alternative approaches like self-joins or subqueries to achieve similar results.



FIRST_VALUE():
    Qn : Write a query to get the most expensive product under each category.
    SELECT *,FIRST_VALUE(product_name)OVER(PARTITION BY product_category ORDER BY price DESC) AS 'exp_prod'
    FROM Products;

LAST_VALUE():
    Qn : Write a query to get the min amount of product under each category.
    SELECT LAST_VALUE(product_name)OVER(PARTITION BY product_category ORDER BY price 
    DESC RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as 'less_prod'
    FROM Products;




TUTORIAL LINK : https://www.youtube.com/watch?v=Ww71knvhQ-s&t=11s


Tutorial Link : https://www.youtube.com/watch?v=zAmJPdZu8Rg