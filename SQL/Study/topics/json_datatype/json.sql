CREATE TABLE json_tbl(
    id INT AUTO_INCREMENT PRIMARY KEY,
    details JSON 
);

SELECT  details->"$.name" AS "full_name", 
details->> "$.email" AS "email" FROM json_tbl;


SELECT  details->"$.name" AS "full_name", 
details->> "$.email" AS "email" FROM json_tbl
WHERE details ->"$.email" = '"ruhul@gmail.com"';


AVAILABLE FUNCTIONS: 

JSON_ARRAY(),JSON_OBJECT(),JSON_TYPE()

