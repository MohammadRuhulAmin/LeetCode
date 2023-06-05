
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