
-- 185. Department Top Three Salaries
WITH CTE AS (
    SELECT * FROM (
        SELECT 
            E.id,
            E.name,
            E.salary,
            DENSE_RANK()OVER(PARTITION BY E.departmentId ORDER BY E.salary DESC) AS 'drnk',
            E.departmentId
        FROM Employee E
    )AS sqry
    WHERE sqry.drnk < 4 
)SELECT D.name AS 'Department', 
    C.name AS 'Employee',
    C.salary AS 'Salary'
 FROM CTE C
 LEFT JOIN 
 Department D
 ON 
 D.id = C.departmentId 


