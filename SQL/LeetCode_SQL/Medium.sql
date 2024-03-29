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

--###################################################################

-- 1393. Capital Gain/Loss
WITH CTE1 AS(
  SELECT stock_name,operation,SUM(price) AS 'Gain'
  FROM Stocks
  WHERE operation = 'Buy'
  GROUP BY stock_name
),
CTE2 AS(
  SELECT stock_name,operation,SUM(price) AS 'Loss' 
  FROM Stocks
  WHERE operation = 'Sell'
  GROUP BY stock_name
)SELECT CTE1.stock_name,
(CTE2.Loss - CTE1.Gain) AS 'capital_gain_loss'
FROM CTE1
JOIN CTE2
ON CTE1.stock_name = CTE2.stock_name;
--######################################################################

-- 1934. Confirmation Rate
-- #####################################################################
WITH CTE AS (
  SELECT 
  S.user_id AS 'suid',S.time_stamp AS 'ststm',
  C.user_id AS 'cuid',C.time_stamp AS 'ctstm',C.action,
  SUM(CASE WHEN C.action = 'timeout' THEN 1 ELSE 0 END) AS 'stout',
  SUM(CASE WHEN C.action = 'confirmed' THEN 1 ELSE 0 END) AS 'sconf'
  FROM Signups S
  LEFT JOIN
  Confirmations C
  ON S.user_id = C.user_id
  GROUP BY S.user_id
  ORDER BY S.user_id ASC
),
CTEx AS(
  SELECT CTE.suid AS 'user_id', 
  ROUND(CTE.sconf/SUM(CTE.stout + CTE.sconf),2) AS 'crate'
  FROM CTE
  GROUP BY CTE.suid
)SELECT CTEx.user_id ,
CASE WHEN CTEx.crate IS NOT NULL THEN CTEx.crate ELSE 0 END AS 'confirmation_rate'
FROM CTEx;

-- ##########################################################################

-- 626. Exchange Seats
SELECT (
    CASE 
        WHEN id%2 != 0 AND id != total_counts THEN id+1
        WHEN id%2 !=0 AND id = total_counts THEN id
        ELSE id - 1
    END 
) AS id,student FROM Seat,
(SELECT COUNT(*) AS total_counts FROM Seat) AS subquery
ORDER BY id ASC


-- #######################################################
-- 550. Game Play Analysis IV
WITH CTE1 AS (
  SELECT player_id,MIN(event_date) AS 'first_log' FROM Activity
  GROUP BY player_id
),
CTE2 AS (
  SELECT CTE1.player_id,
  CTE1.first_log,
  DATE_ADD(CTE1.first_log,INTERVAL 1 DAY) AS 'next' FROM CTE1
)SELECT ROUND(COUNT(*)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS 'fraction' FROM CTE2
WHERE (CTE2.player_id,CTE2.next) IN (SELECT player_id,event_date FROM Activity)


-- ###############################################
-- 1174. Immediate Food Delivery II
WITH CTE1 AS(
  SELECT customer_id,MIN(order_date) AS 'order_date' FROM 
  Delivery
  GROUP BY customer_id
),
CTE2 AS (
  SELECT CTE1.* FROM CTE1
  WHERE (CTE1.customer_id,CTE1.order_date) IN
  (SELECT D.customer_id,D.customer_pref_delivery_date FROM Delivery D)
)
SELECT ROUND( 100*COUNT(CTE2.customer_id)/countQuery.cid,2) AS 'immediate_percentage'
FROM CTE2,(SELECT COUNT(DISTINCT customer_id) AS cid FROM  Delivery) AS countQuery

-- ##############################################

-- 608. Tree Node


SELECT id,
CASE 
    WHEN p_id IS NULL THEN 'Root'
    WHEN id NOT IN(SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf'
    ELSE 'Inner'
END
AS 'type'
FROM Tree

-- ###########################################################
--570. Managers with at Least 5 Direct Reports
WITH CTE AS (
  SELECT managerId , COUNT(managerId) AS 'cnt'
  FROM Employee
  WHERE managerId NOT IN ('None')
  GROUP BY managerId

)SELECT E.name FROM Employee E
INNER JOIN CTE 
ON E.id = CTE.managerId
WHERE CTE.cnt >=5

-- ###################################################
-- 1341. Movie Rating
WITH CTE1 AS (
    SELECT user_id,COUNT(movie_id) AS 't_rate'
    FROM MovieRating 
    GROUP BY user_id
),
CTE2 AS (
    SELECT CTE1.user_id,U.name , CTE1.t_rate 
    FROM CTE1
    INNER JOIN 
    Users U
    ON CTE1.user_id = U.user_id
),
CTE3_f AS (
    SELECT MIN(CTE2.name) AS 'results'
    FROM CTE2 WHERE CTE2.t_rate =  (SELECT MAX(CTE2.t_rate) FROM CTE2)
),
CTE3 AS (
    SELECT movie_id,AVG(rating) AS 'rt' FROM MovieRating
    WHERE created_at BETWEEN "2020-02-01" AND "2020-02-29"
    GROUP BY movie_id
),
CTE4 AS (
  SELECT CTE3.movie_id, M.title ,CTE3.rt 
  FROM CTE3 
  INNER JOIN Movies M
  ON 
  CTE3.movie_id = M.movie_id 
),
CTE5 AS (
  SELECT MIN(CTE4.title) AS 'results' FROM CTE4
  WHERE  CTE4.rt = (SELECT MAX(CTE4.rt) FROM CTE4)
)

SELECT CTE3_f.results FROM CTE3_f
UNION ALL
SELECT CTE5.results FROM CTE5

-- ########################################################


-- 1164. Product Price at a Given Date
WITH CTE AS (
    SELECT * FROM (
      SELECT 
          P.product_id,
          P.change_date,
          P.new_price,
              ROW_NUMBER() OVER(PARTITION BY P.product_id ORDER BY P.change_date DESC) AS 'rnk'
          FROM Products P 
          WHERE  
          P.change_date <='2019-08-16'

      ) AS sqry
    GROUP BY sqry.product_id
    ORDER BY sqry.change_date DESC
)
SELECT DISTINCT P.product_id, IF(C.new_price IS NULL ,10 , C.new_price) AS 'price'
FROM CTE C
RIGHT JOIN 
Products P 
ON 
C.product_id = P.product_id

-- ########################




