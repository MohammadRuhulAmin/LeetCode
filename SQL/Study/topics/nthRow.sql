Display the Nth Row in the Table : 


i want to display only the 5th row in the table : 


SELECT *
FROM Employees
LIMIT 1 OFFSET (5-1);

OFFSET (5 - 1): This specifies the number of rows to skip before starting to return the result set. 
In this case, it skips 4 rows (5 - 1 = 4) before returning the result.




To display records from the nth to mth row in SQL, you can use the combination of the LIMIT and OFFSET clauses. 
The LIMIT clause specifies the maximum number of rows to return, and the OFFSET clause specifies the number of rows to skip before starting to return the result set.

SELECT *
FROM Employees
LIMIT (m - n + 1) OFFSET (n - 1);

SELECT *
FROM Employees
LIMIT (10 - 5 + 1) OFFSET (5 - 1);

