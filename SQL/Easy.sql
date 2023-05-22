
--182 Dublicate emails:
select email from Person 
group by email having Count(*)>1
