
-- ################################################
--182 Dublicate emails:
select email from Person 
group by email having Count(*)>1

-- ###############################################


-- ###############################################
--175 Combine Two Tables 
select t1.firstName,t1.lastName,t2.city,t2.state
from Person t1 
LEFT JOIN
Address t2
ON
t1.personId = t2.personId;

-- ################################################


-- ################################################
--577.Employee Bonus
SELECT t1.name,t2.bonus 
FROM
Employee t1
LEFT JOIN
Bonus t2
ON
t1.empId = t2.empId
where
t2.bonus < 1000 OR t2.bonus is NULL

-- #########################################################

-- #########################################################
--196. Delete Duplicate Emails
Delete t2 from Person t1 JOIN Person t2
ON t1.email = t2.email
and t1.id<t2.id
-- #########################################################

-- ########################################################
--183. Customers Who Never Order
SELECT name as Customers from Customers t1
LEFT JOIN Orders t2
ON t1.id = t2.customerID
where t2.customerId is NULL 

-- #######################################################

-- #######################################################
--584. Find Customer Referee

select name from Customer 
where 
referee_id is NULL
OR
referee_id  !=2

-- #####################################################


-- #####################################################
--595. Big Countries
SELECT name,population,area FROM
World
WHERE area>=3000000 
OR
population >=25000000

-- ####################################################


-- ####################################################
--610. Triangle Judgement
SELECT x,y,z, 
IF(x+y>z and y+z>x and z+x>y,"Yes","No") as triangle
FROM Triangle
-- ###################################################

-- ###################################################
--619. Biggest Single Number
WITH NumList AS (

  SELECT num
  FROM MyNumbers
  GROUP BY num
  HAVING count(*) = 1

) SELECT MAX(num) as num FROM NumList

-- ##################################################

-- ##################################################
--1978. Employees Whose Manager Left the Company
SELECT employee_id FROM Employees 
WHERE salary < 30000 
AND 
manager_id NOT IN ( 
  SELECT employee_id FROM Employees
) 
ORDER BY employee_id asc
-- #################################################

-- #################################################
--1327. List the Products Ordered in a Period
SELECT t1.product_name,sum(t2.unit) as unit FROM
Products t1 JOIN Orders t2
ON t1.product_id = t2.product_id 
WHERE t2.order_date LIKE '2020-02%'
GROUP BY t1.product_id 
HAVING SUM(t2.unit)>=100

-- ################################################

-- ################################################
--1890. The Latest Login in 2020
SELECT user_id,MAX(time_stamp) AS last_stamp
FROM Logins
WHERE time_stamp LIKE  "2020-%"
GROUP BY user_id

-- ################################################

-- ################################################
--1075. Project Employees I
SELECT t1.project_id,ROUND(avg(t2.experience_years),2) as average_years FROM 
Project t1
LEFT JOIN
Employee t2
ON t1.employee_id = t2.employee_id
GROUP BY
t1.project_id
-- ##############################################

-- #############################################
-- 627. Swap Salary
UPDATE Salary
SET
Sex = if(sex = 'm','f','m')
-- ############################################

-- ############################################
--620. Not Boring Movies
SELECT id,movie,description,rating
FROM
Cinema
WHERE id%2 != 0
AND 
description !="boring"
ORDER BY
rating desc
-- #########################################

-- #########################################
-- 1068. Product Sales Analysis I
SELECT t1.product_name,t2.year,t2.price
FROM Product t1
JOIN
Sales t2 
ON t1.product_id = t2.product_id
-- #########################################

-- ###########################################
--1667. Fix Names in a Table
SELECT user_id,
CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2,LENGTH(name)))) 
AS name
FROM Users 
ORDER BY
user_id ASC
-- ###########################################

-- ###########################################
--1757. Recyclable and Low Fat Products

SELECT product_id 
FROM Products
WHERE 
(low_fats = 'Y' AND recyclable = 'Y')
-- ########################################

-- #######################################
-- 1729. Find Followers Count
SELECT  user_id,COUNT(user_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC
-- #########################################

-- #######################################################
-- 1731. The Number of Employees Which Report to Each Employee
WITH TempTbl AS(
  SELECT reports_to AS employee_id,COUNT(employee_id) AS reports_count,
  ROUND(AVG(age),0) AS average_age 
  FROM Employees
  WHERE reports_to is NOT NULL
  GROUP BY reports_to
)
SELECT TempTbl.employee_id,joinTbl.name,TempTbl.reports_count,TempTbl.average_age 
FROM TempTbl
JOIN Employees joinTbl
ON TempTbl.employee_id = joinTbl.employee_id
ORDER BY TempTbl.employee_id ASC
-- #######################################################

-- ########################################################
-- 1407. Top Travellers
WITH CTE AS(
  SELECT user_id,SUM(distance) AS travelled_distance FROM Rides
  GROUP BY user_id
)
SELECT t1.name,IF(CTE.travelled_distance IS NULL,0,CTE.travelled_distance) AS travelled_distance FROM Users t1
LEFT JOIN CTE ON t1.id = CTE.user_id
ORDER BY travelled_distance DESC, name ASC
-- ##############################################################

-- ##############################################################
--1517. Find Users With Valid E-Mails

SELECT user_id, name, mail
FROM Users
WHERE mail REGEXP '^[A-Za-z]([A-Za-z0-9\.\_\-]+)?@leetcode[.]com';

-- #############################################################

-- #############################################################
-- 1633. Percentage of Users Attended a Contest

SELECT contest_id,
       ROUND(100*COUNT(contest_id)/(SELECT COUNT(DISTINCT user_id) FROM USERS),2)  AS  percentage 
FROM Register 
GROUP BY contest_id
ORDER BY percentage DESC,
         contest_id ASC

-- #############################################################

-- #############################################################
--1484. Group Sold Products By The Date

SELECT 
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date
-- ############################################################


-- ############################################################
-- 1587. Bank Account Summary II
WITH CTE AS(
    SELECT account,SUM(amount) AS balance 
    FROM Transactions
    GROUP By account

)SELECT u.name AS NAME,CTE.balance AS BALANCE FROM Users u
JOIN CTE
ON
u.account = CTE.account
WHERE BALANCE > 10000
-- ###########################################################

-- ###########################################################
--1683. Invalid Tweets

SELECT tweet_id FROM Tweets
WHERE LENGTH(content) >15
-- ###########################################################


-- ###########################################################
--1693. Daily Leads and Partners
SELECT date_id,
       make_name,
       COUNT(distinct lead_id )AS unique_leads,COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id,make_name
-- ###########################################################

-- ###########################################################
--1741. Find Total Time Spent by Each Employee

SELECT event_day AS day ,emp_id,sum(out_time - in_time) AS total_time
FROM Employees
GROUP BY emp_id,event_day
WHERE emp_id = 1 AND event_day = "2020-11-28"
-- ###########################################################


-- ###########################################################
--1965. Employees With Missing Information
SELECT employee_id FROM Employees
WHERE employee_id NOT IN 
(SELECT employee_id FROM Salaries )
UNION
SELECT employee_id FROM Salaries
WHERE employee_id NOT IN
(SELECT employee_id FROM Employees)
ORDER BY employee_id ASC

-- ##########################################################


-- ##########################################################
-- 1873. Calculate Special Bonus
 SELECT 
    employee_id,
    IF(employee_id%2 !=0 AND name NOT LIKE('M%'),salary,0) AS bonus
FROM  Employees
ORDER BY employee_id
-- ##########################################################


-- ##########################################################
--1795. Rearrange Products Table

SELECT product_id,'store1' AS store,store1 AS price FROM Products
WHERE store1 is NOT NULL
UNION
SELECT product_id,'store2' AS store,store2 AS price FROM Products
WHERE store2 is NOT NULL
UNION
SELECT product_id,'store3' AS store3,store3 AS price FROM Products
WHERE store3 is NOT NULL
-- #########################################################

-- #########################################################
--596. Classes More Than 5 Students
SELECT class FROM Courses
GROUP BY class
HAVING COUNT(class)>4
-- #########################################################

-- #########################################################
-- 511. Game Play Analysis I
SELECT  
  player_id,
  MIN(event_date) AS first_login
  FROM Activity 
  GROUP BY player_id

-- ##########################################################

-- ##########################################################
--1050. Actors and Directors Who Cooperated At Least Three Times

SELECT actor_id,director_id FROM ActorDirector
GROUP BY actor_id,director_id
HAVING COUNT(*)>2
-- ########################################################



-- ###########################################################
-- 1789. Primary Department for Each Employee
SELECT 
      employee_id,
      CASE
          WHEN COUNT(department_id) = 1 THEN department_id
          WHEN COUNT(employee_id)>1 THEN SUM((primary_flag = 'Y')*department_id) 
      END AS department_id
FROM Employee
GROUP BY employee_id;
-- ############################################################

-- ############################################################
--2356. Number of Unique Subjects Taught by Each Teacher

SELECT teacher_id,COUNT(DISTINCT subject_id) AS cnt
FROM Teacher 
GROUP BY teacher_id

-- ##########################################################

-- ##########################################################
-- 1251. Average Selling Price
SELECT P.product_id, 
    ROUND(SUM(P.price*U.units)/SUM(U.units),2) AS average_price
FROM Prices P
LEFT JOIN UnitsSold U
ON P.product_id = U.product_id
WHERE U.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY product_id

-- ##########################################################

-- ##########################################################
-- 1148. Article Views I
SELECT DISTINCT author_id AS id FROM Views
WHERE author_id = viewer_id
ORDER BY author_id ASC

-- ############################################################################
-- 1179. Reformat Department Table

SELECT
    id,
    SUM(CASE WHEN month = 'Jan' THEN revenue END) AS 'Jan_Revenue' ,
    SUM(CASE WHEN month = 'Feb' THEN revenue END) AS 'Feb_Revenue',
    SUM(CASE WHEN month = 'Mar' THEN revenue END) AS 'Mar_Revenue',
    SUM(CASE WHEN month = 'Apr' THEN revenue END) AS 'Apr_Revenue',
    SUM(CASE WHEN month = 'May' THEN revenue END) AS 'May_Revenue',
    SUM(CASE WHEN month = 'Jun' THEN revenue END) AS 'Jun_Revenue',
    SUM(CASE WHEN month = 'Jul' THEN revenue END) AS 'Jul_Revenue',
    SUM(CASE WHEN month = 'Aug' THEN revenue END) AS 'Aug_Revenue',
    SUM(CASE WHEN month = 'Sep' THEN revenue END) AS 'Sep_Revenue',
    SUM(CASE WHEN month = 'Oct' THEN revenue END) AS 'Oct_Revenue',
    SUM(CASE WHEN month = 'Nov' THEN revenue END) AS 'Nov_Revenue',
    SUM(CASE WHEN month = 'Dec' THEN revenue END) AS 'Dec_Revenue'
FROM Department
GROUP BY id
ORDER BY id ASC


-- #######################################################################

-- 1527. Patients With a Condition

SELECT patient_id,patient_name,conditions
FROM Patients 
WHERE conditions
LIKE '% DIAB1%'
OR conditions LIKE 'DIAB1%'



-- 586. Customer Placing the Largest Number of Orders
SELECT customer_number FROM Orders
GROUP BY customer_number
Order BY COUNT(customer_number) DESC LIMIT 1


-- ############################################################################

-- 1581. Customer Who Visited but Did Not Make Any Transactions

WITH CTE AS(

  select v.customer_id,v.visit_id,t.transaction_id,t.amount FROM
  Visits v LEFT JOIN Transactions t
  ON
  v.visit_id = t.visit_id
  WHERE t.transaction_id IS NULL
)SELECT CTE.customer_id,COUNT(CTE.visit_id) AS "count_no_trans"
 FROM CTE 
GROUP BY CTE.customer_id;

--###############################################################################

-- 1280. Students and Examinations

WITH cte1 AS(
    SELECT st.student_id,st.student_name,sj.subject_name 
    FROM Students st
    CROSS JOIN
    Subjects sj 
),cte2 AS(
    SELECT ex.student_id, ex.subject_name, COUNT(ex.subject_name) AS attended_exams
    FROM Examinations ex
    GROUP BY ex.student_id,ex.subject_name

)SELECT cte1.student_id,cte1.student_name,cte1.subject_name,if(cte2.attended_exams IS NULL,0,cte2.attended_exams) as attended_exams
FROM cte1 LEFT JOIN cte2
ON cte1.student_id = cte2.student_id
AND cte1.subject_name = cte2.subject_name
ORDER BY cte1.student_id,cte1.subject_name

--###################################################################

-- 1378. Replace Employee ID With The Unique Identifier
SELECT u.unique_id,e.name
FROM Employees e
LEFT JOIN
EmployeeUNI u
ON
e.id = u.id

-- ###################################################################

