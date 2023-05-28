
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