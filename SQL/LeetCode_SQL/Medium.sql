-- #################################################################################
--176. Second Highest Salary

SELECT MAX(Salary) as SecondHighestSalary
FROM Employee
Where 
Salary < (SELECT MAX(Salary) FROM Employee)
-- #################################################################################

-- #################################################################################
--1907. Count Salary Categories

SELECT 'Low Salary' AS 'category' , COUNT(income) AS accounts_count  FROM Accounts 
WHERE income < 20000
UNION
SELECT 'Average Salary' AS 'category',COUNT(income) AS accounts_count FROM Accounts
WHERE income BETWEEN 20000 AND 50000
UNION
SELECT 'High Salary' AS 'category',COUNT(income) AS accounts_count FROM Accounts
WHERE income > 50000
-- #################################################################################
-- #################################################################################
--177. Nth Highest Salary

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN 
  SET N = N-1;
  RETURN (
      SELECT DISTINCT salary FROM Employee ORDER BY salary DESC 
      LIMIT 1 OFFSET N
  );
END 

-- #################################################################################

-- #################################################################################
--180. Consecutive Numbers
WITH CTE AS(
        SELECT id,num,
                LEAD(num)OVER() AS next1,LEAD(num,2)OVER() AS next2
        FROM Logs
)SELECT DISTINCT CTE.num AS 'ConsecutiveNums' FROM CTE
WHERE CTE.num = CTE.next1 AND CTE.num = CTE.next2
-- #################################################################################


-- #################################################################################
--184. Department Highest Salary
SELECT D.name AS Department,E.name AS Employee,salary AS Salary
FROM Employee E
LEFT JOIN Department D
ON E.departmentId= D.id
 WHERE (departmentId,salary) 
 IN(
  SELECT departmentId,MAX(salary) FROM Employee
  GROUP BY departmentId
)

-- #################################################################################
-- 1045. Customers Who Bought All Products

SELECT customer_id
FROM Customer 
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product)
-- #################################################################################
-- #################################################################################
-- 1070. Product Sales Analysis III

WITH cte AS(
  SELECT product_id,year,quantity,price ,
  RANK() OVER(PARTITION BY product_id ORDER BY year ASC) AS rnk
  FROM Sales
)SELECT cte.product_id,cte.year AS first_year,cte.quantity,cte.price
 FROM cte WHERE cte.rnk = 1
-- #################################################################################


-- ################################################################################

--1158. Market Analysis I
WITH cte AS(
    SELECT u.user_id,u.join_date,o.order_date
    FROM Users u
    LEFT JOIN Orders o
    ON u.user_id = o.buyer_id

)SELECT cte.user_id AS 'buyer_id',
cte.join_date, SUM(
  CASE
    WHEN YEAR(cte.order_date) = 2019 THEN 1 ELSE 0
    END 
)AS 'orders_in_2019'
FROM cte 

GROUP BY cte.user_id


 --###########################################################
