Tutorial link : https://www.youtube.com/watch?v=cjCLSq4ZZHU
Step : 1

CREATE TABLE Employee_details(
	id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    gender VARCHAR(50) NOT NULL,
    designation VARCHAR(50) NOT NULL,
    city VARCHAR(50) NOT NULL,
    salary INT NOT NULL
)ENGINE=INNODB;

INSERT INTO Employee_details (name, gender, designation, city, salary)
VALUES 
    ('Ruhul', 'Male', 'Manager', 'Dhaka', 40000),
    ('John', 'Male', 'Developer', 'New York', 50000),
    ('Emma', 'Female', 'Sales Associate', 'London', 35000),
    ('Michael', 'Male', 'Assistant Manager', 'Sydney', 45000),
    ('Sophia', 'Female', 'HR Coordinator', 'Berlin', 38000),
    ('David', 'Male', 'Analyst', 'Toronto', 42000),
    ('Sarah', 'Female', 'Marketing Specialist', 'Paris', 39000),
    ('Daniel', 'Male', 'Designer', 'Los Angeles', 48000),
    ('Olivia', 'Female', 'Accountant', 'Tokyo', 41000),
    ('James', 'Male', 'Engineer', 'Singapore', 44000),
    ('Emily', 'Female', 'Project Manager', 'Melbourne', 47000),
    ('William', 'Male', 'Supervisor', 'Chicago', 43000),
    ('Ava', 'Female', 'Quality Assurance', 'Mumbai', 36000),
    ('Alexander', 'Male', 'Team Lead', 'Dubai', 46000),
    ('Mia', 'Female', 'Administrator', 'Stockholm', 40000);



to make a table we have to use Engine= INNODB;

Step : 2 

START TRANSACTION;
DELETE FROM Employee_details;
SELECT * FROM Employee_details;
ROLLBACK; -- or COMMIT;

the four statement will be consider as one statement. 
if any of the substatement doesnt execute the whole statements will be rollbacked!

or more example : 

START TRANSACTION;
SELECT * FROM Employee_details;
DELETE  FROM Employee_details where id between 1 and 8;
COMMIT;




