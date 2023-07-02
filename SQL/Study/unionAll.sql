SELECT name FROM customers
UNION ALL
SELECT name FROM employees;


using UNION ALL, if the repeated value stays in boot column of both tables
the value will show repeated .

