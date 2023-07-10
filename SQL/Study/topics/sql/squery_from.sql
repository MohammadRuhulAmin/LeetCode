
Sub query after from clause.. 

SELECT dept_name,avg_salary 
FROM (
    SELECT dept_name,avg(salary) AS 'avg_salary' FROM Instructor 
    GROUP BY deptName 
    WHERE avg_salary>42000
)


SELECT T.name,T.salary FROM 
(SELECT name,salary   FROM Employees) AS T



SELECT T.name,T.sal FROM 
(SELECT name,SUM(salary) AS 'sal' FROM Employees GROUP BY department_id ORDER BY salary ) AS T