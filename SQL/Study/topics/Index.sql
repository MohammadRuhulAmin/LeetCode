INDEX Command Syntax : 
    
    Create indexing :
    CREATE INDEX index_name
    ON table_name(column1,column2,column3)

    Drop indexing :
    DROP INDEX index_name 
    ON Table_name;


To see the index in the table  
SHOW INDEX FROM Table_Name;

To Drop index from a table 
DROP INDEX index_name ON Table_Name; 






Why we need indexing ? 
Ans :
1. Automatically creates the indexes for primary key and unique columns 
2. index columns that you frequently use to retrieve the data 
3.Index columns that are used for joins to improve join performance
4.Avoid columns that contain too many null values 
5.Small tables do not require indexes.     