
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

 

TUTORIAL LINK : https://www.youtube.com/watch?v=Ww71knvhQ-s&t=11s