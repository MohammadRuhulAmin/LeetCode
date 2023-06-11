
--176. Second Highest Salary

SELECT MAX(Salary) as SecondHighestSalary
FROM Employee
Where 
Salary < (SELECT MAX(Salary) FROM Employee)



--1907. Count Salary Categories

SELECT 'Low Salary' AS 'category' , COUNT(income) AS accounts_count  FROM Accounts 
WHERE income < 20000
UNION
SELECT 'Average Salary' AS 'category',COUNT(income) AS accounts_count FROM Accounts
WHERE income BETWEEN 20000 AND 50000
UNION
SELECT 'High Salary' AS 'category',COUNT(income) AS accounts_count FROM Accounts
WHERE income > 50000


--177. Nth Highest Salary

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN 
  SET N = N-1;
  RETURN (
      SELECT DISTINCT salary FROM Employee ORDER BY salary DESC 
      LIMIT 1 OFFSET N
  );
END 




--180. Consecutive Numbers
WITH CTE AS(
        SELECT id,num,
                LEAD(num)OVER() AS next1,LEAD(num,2)OVER() AS next2
        FROM Logs
)SELECT DISTINCT CTE.num AS 'ConsecutiveNums' FROM CTE
WHERE CTE.num = CTE.next1 AND CTE.num = CTE.next2