SOME , ANY , ALL :

If a Subquery returns more than one value, that time we have to 
use SOME, ANY or ALL 

LIKE 
Outer Query > SOME (Inner Query) 
Outer Query < ANY (Inner Query) 
Outer Query = ALL (Inner Query)




Example : 

SELECT * FROM Products WHERE price > ALL (SELECT salary FROM Products WHERE category = 'Electronics')

SELECT * FROM Products WHERE price > ANY (SELECT salary FROM Products WHERE category = 'Electronics')

SELECT * FROM Products WHERE price > SOME (SELECT salary FROM Products WHERE category = 'Electronics')


Here both ANY and SOME will return the same results. Using Any key, the lowest salary will be returned 
from inner query. and same thing will be happened with SOME. 

