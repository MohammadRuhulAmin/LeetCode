
https://www.youtube.com/watch?v=Rhz9HpqSan0

Index command : 
    CREATE INDEX index_name 
    ON table_name(column1,column2,column3,....);

Drop command :
 DROP INDEX index_name
 ON table_name;

SHOW INDEX command:
    SHOW INDEX FROM students;
    


making index during table creation:
CREATE TABLE table_name(
    id AUTO_INCREMENT UNIQUE,
    name VARCHAR(30),
    email VARCHAR(30),
    INDEX index_name (name)
)


WHY we use indexin ? 
==> INDEX columns that are used for joins to imporve join performance.

Important Point : 
1. Automatically creates the indexes for PRIMARY KEY AND UNIQUE columns 
2. index columns that you frequently use to retrieve the data. 
3. Avoid columns that contain too many NULL values.
4.Small tables do not require indexes.
