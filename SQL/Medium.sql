
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