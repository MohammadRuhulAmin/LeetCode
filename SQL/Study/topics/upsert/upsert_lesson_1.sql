
Referance : https://www.javatpoint.com/mysql-upsert

 UPSERT is one of the essential features of DBMS software for managing the database. This operation allows the DML users to insert a new record or update existing data into a table. An UPSERT is made up of a combination of two words named UPDATE and INSERT.
 The first two letters, i.e., UP stands for UPDATE while the SERT stands for INSERT. 
 The UPSERT is an atomic operation that means it is an operation that completes in a single-step. 
 For example, if a record is new, it will trigger an INSERT command. But, 
 if it already exists in the table, then this operation will perform an UPDATE statement.

By default, MySQL provides the ON DUPLICATE KEY UPDATE option to INSERT, 
which accomplishes this task. However, it also contains some other statements to fulfill this objective, such as INSERT IGNORE or REPLACE. We will learn and see all these solutions in detail.
We can perform MySQL UPSERT operation mainly in three ways, which are as follows:
UPSERT using INSERT IGNORE
    INSERT IGNORE INTO employee_details VALUES(1,'Ruhul','Male','Manager','Dhaka',40000)
    will provide a warning!
UPSERT using REPLACE
UPSERT using INSERT ON DUPLICATE KEY UPDATE


UPSERT using Insert IGNORE:
crreating table: 
    CREATE TABLE Student (  
    Stud_ID int AUTO_INCREMENT PRIMARY KEY,  
    Name varchar(45) DEFAULT NULL,  
    Email varchar(45) NOT NULL UNIQUE,  
    City varchar(25) DEFAULT NULL  
    );  


INSERT IGNORE INTO Student(Stud_ID, Name, Email, City)   
VALUES (1,'Stephen', 'stephen@javatpoint.com', 'Texas'),   
(2, 'Joseph', 'Joseph@javatpoint.com', 'Alaska'),   
(3, 'Peter', 'Peter@javatpoint.com', 'California');  


UPSERT using REPLACE
REPLACE INTO Student(Stud_ID, Name, Email, City)   
VALUES (1,'hegen', 'stephen@javatpoint.com', 'Texas');



UPSERT using INSERT ON DUPLICATE KEY UPDATE
We have seen the two UPSERT commands so far, but they had some limitations. The INSERT IGNORE statement only ignores the duplicate error without making any modification to the table. And the REPLACE method detected the INSERT error, but it will delete the row before adding the new record. Hence, we are still searching for a more refined solution until now.

So, we use a more refined solution as the INSERT ON DUPLICATE KEY UPDATE statement. It is a non-destructive method that means it does not remove the duplicate row. Instead, when we specify the ON DUPLICATE KEY UPDATE clause in a SQL statement and a row would cause duplicate error value in a UNIQUE or PRIMARY KEY index column, then updation of the existing row occurs.

The syntax of Insert on Duplicate Key Update statement in MySQL is given below:

INSERT INTO table (column_names)  
VALUES (data)  
ON DUPLICATE KEY UPDATE   
column1 = expression, column2 = expression...;  


example : 
INSERT INTO Student(Stud_ID, Name, Email, City)   
VALUES (4, 'John', 'john@javatpoint.com', 'New York')  
ON DUPLICATE KEY UPDATE City = 'California',Name = 'xx'; 