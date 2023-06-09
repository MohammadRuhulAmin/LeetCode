
--182 Dublicate emails:
select email from Person 
group by email having Count(*)>1



--175 Combine Two Tables 
select t1.firstName,t1.lastName,t2.city,t2.state
from Person t1 
LEFT JOIN
Address t2
ON
t1.personId = t2.personId;



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



--196. Delete Duplicate Emails
Delete t2 from Person t1 JOIN Person t2
ON t1.email = t2.email
and t1.id<t2.id


--183. Customers Who Never Order
SELECT name as Customers from Customers t1
LEFT JOIN Orders t2
ON t1.id = t2.customerID
where t2.customerId is NULL 


--584. Find Customer Referee

select name from Customer 
where 
referee_id is NULL
OR
referee_id  !=2



--595. Big Countries
SELECT name,population,area FROM
World
WHERE area>=3000000 
OR
population >=25000000




--610. Triangle Judgement
SELECT x,y,z, 
IF(x+y>z and y+z>x and z+x>y,"Yes","No") as triangle
FROM Triangle


--619. Biggest Single Number
WITH NumList AS (

  SELECT num
  FROM MyNumbers
  GROUP BY num
  HAVING count(*) = 1

) SELECT MAX(num) as num FROM NumList



--1978. Employees Whose Manager Left the Company
SELECT employee_id FROM Employees 
WHERE salary < 30000 
AND 
manager_id NOT IN ( 
  SELECT employee_id FROM Employees
) 
ORDER BY employee_id asc


--1327. List the Products Ordered in a Period
SELECT t1.product_name,sum(t2.unit) as unit FROM
Products t1 JOIN Orders t2
ON t1.product_id = t2.product_id 
WHERE t2.order_date LIKE '2020-02%'
GROUP BY t1.product_id 
HAVING SUM(t2.unit)>=100



--1890. The Latest Login in 2020
SELECT user_id,MAX(time_stamp) AS last_stamp
FROM Logins
WHERE time_stamp LIKE  "2020-%"
GROUP BY user_id



--1075. Project Employees I
SELECT t1.project_id,ROUND(avg(t2.experience_years),2) as average_years FROM 
Project t1
LEFT JOIN
Employee t2
ON t1.employee_id = t2.employee_id
GROUP BY
t1.project_id


-- 627. Swap Salary
UPDATE Salary
SET
Sex = if(sex = 'm','f','m')


--620. Not Boring Movies
SELECT id,movie,description,rating
FROM
Cinema
WHERE id%2 != 0
AND 
description !="boring"
ORDER BY
rating desc



-- 1068. Product Sales Analysis I
SELECT t1.product_name,t2.year,t2.price
FROM Product t1
JOIN
Sales t2 
ON t1.product_id = t2.product_id



--1667. Fix Names in a Table
SELECT user_id,
CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2,LENGTH(name)))) 
AS name
FROM Users 
ORDER BY
user_id ASC



--1757. Recyclable and Low Fat Products

SELECT product_id 
FROM Products
WHERE 
(low_fats = 'Y' AND recyclable = 'Y')


-- 1729. Find Followers Count
SELECT  user_id,COUNT(user_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC


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


-- 1407. Top Travellers
WITH CTE AS(
  SELECT user_id,SUM(distance) AS travelled_distance FROM Rides
  GROUP BY user_id
)
SELECT t1.name,IF(CTE.travelled_distance IS NULL,0,CTE.travelled_distance) AS travelled_distance FROM Users t1
LEFT JOIN CTE ON t1.id = CTE.user_id
ORDER BY travelled_distance DESC, name ASC


--1517. Find Users With Valid E-Mails

SELECT user_id, name, mail
FROM Users
WHERE mail REGEXP '^[A-Za-z]([A-Za-z0-9\.\_\-]+)?@leetcode[.]com';


-- 1633. Percentage of Users Attended a Contest

SELECT contest_id,
       ROUND(100*COUNT(contest_id)/(SELECT COUNT(DISTINCT user_id) FROM USERS),2)  AS  percentage 
FROM Register 
GROUP BY contest_id
ORDER BY percentage DESC,
         contest_id ASC


--1484. Group Sold Products By The Date
SELECT 
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date
 
