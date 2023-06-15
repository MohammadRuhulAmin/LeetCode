CREATE TABLE employees(
	id int AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(30),
    dep_id int,
    salary int
);


INSERT INTO employees(name,dep_id,salary)VALUES("ruhul",1,300);
INSERT INTO employees(name,dep_id,salary)VALUES("sakib",1,20000);
INSERT INTO employees(name,dep_id,salary)VALUES("sajid",2,15000);
INSERT INTO employees(name,dep_id,salary)VALUES("sai",2,1200);
INSERT INTO employees(name,dep_id,salary)VALUES("pothik",3,1000);
INSERT INTO employees(name,dep_id,salary)VALUES("kurban",3,4500);
INSERT INTO employees(name,dep_id,salary)VALUES("panai",4,30000);
INSERT INTO employees(name,dep_id,salary)VALUES("ponkoj",4,30000);
INSERT INTO employees(name,dep_id,salary)VALUES("john",4,30);
INSERT INTO employees(name,dep_id,salary)VALUES("Joshim",3,10);


SELECT id ,name , dep_id,salary ,
RANK() OVER(ORDER BY salary DESC,dep_id ASC) AS rnk ,
DENSE_RANK() OVER(ORDER BY salary DESC) AS drnk,
ROW_NUMBER() OVER(ORDER BY salary DESC ) AS rw
FROM employees;



SELECT id ,name , dep_id,salary ,
RANK() OVER(PARTITION BY dep_id ORDER BY salary ASC) AS rnk ,
DENSE_RANK() OVER(PARTITION BY dep_id ORDER BY salary ASC) AS drnk,
ROW_NUMBER() OVER(PARTITION BY dep_id ORDER BY salary ASC) AS rw
FROM employees;

