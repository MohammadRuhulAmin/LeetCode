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

--############################################################
 -- 602. Friend Requests II: Who Has the Most Friends
WITH cte AS(
  SELECT requester_id AS id,accepter_id
  FROM RequestAccepted 

  UNION
  SELECT accepter_id AS id ,requester_id
  FROM RequestAccepted

)SELECT CTE.id,COUNT(CTE.id) AS 'num'
FROM CTE GROUP BY CTE.id 
ORDER BY COUNT(CTE.id) DESc
LIMIT 1;

-- Alternative solution
WITH cte1 AS(
  SELECT requester_id AS id,accepter_id
  FROM RequestAccepted 

  UNION
  SELECT accepter_id AS id ,requester_id
  FROM RequestAccepted

),cte2 AS(
  SELECT cte1.id,COUNT(cte1.id) AS 'num'
  FROM cte1 GROUP BY cte1.id 
  ORDER BY COUNT(cte1.id) DESC
)SELECT cte2.id , MAX(cte2.num) AS 'num' FROM cte2;

-- ##################################################################
-- 1204. Last Person to Fit in the Bus
WITH CTE AS(
    SELECT *, SUM(weight) 
    OVER (ORDER BY turn ASC ROWS BETWEEN UNBOUNDED    PRECEDING AND CURRENT    ROW) AS 'sum'
FROM Queue
)SELECT  CTE.person_name FROM CTE WHERE CTE.sum <=1000 ORDER BY CTE.sum DESC LIMIT 1 ;

-- ##################################################################

-- 1193. Monthly Transactions I
SELECT DATE_FORMAT(trans_date,'%Y-%m') AS 'month', 
country,
COUNT(id) AS 'trans_count',
SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS 'approved_count',
SUM(amount) AS 'trans_total_amount',
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS 'approved_total_amount'
FROM 
Transactions
GROUP BY country,month

-- ##################################################################
 -- 178. Rank Scores
 SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
 FROM Scores ORDER BY score DESC;
