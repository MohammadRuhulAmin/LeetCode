
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

