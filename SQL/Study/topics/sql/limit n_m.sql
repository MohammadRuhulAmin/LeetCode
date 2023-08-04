create table date_sort(
id int auto_increment primary key,
created date 
);

insert into date_sort(created)values('2011-10-12');
select * from date_sort order by created;
select distinct created from date_sort order by created limit 3,1;


    The ORDER BY date_column ASC clause will sort the dates in ascending order.
    The LIMIT 2, 1 clause will start from the third row (skipping the first two rows) and retrieve only one row, which will be the 3rd minimum date.

With this query, you will indeed get the 3rd minimum date from the table.
here limit 3 means skiping the first 3 row then print the row!

select distinct created from date_sort order by created limit 3, 2;
similarly here the 3 means the first 3 rows will be skiped and 2 means the next 2 rows 
will be selected and print 

in a final :
select * from table_name limit n,m;
here m = limit value 
and n = offset value 

