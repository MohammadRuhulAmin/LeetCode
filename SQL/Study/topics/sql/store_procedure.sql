DELIMITER $$
CREATE PROCEDURE find_app_idv(IN id INT)
BEGIN
    SELECT * FROM application_reports 
    WHERE application_id = id;
END $$
DELIMITER ;

CALL find_app_idv(166);



DROP PROCEDURE find_app_idv;


Example :
DELIMITER $$
    CREATE PROCEDURE find_customer(IN f_name VARCHAR(50),IN l_name VARCHAR(50))
    BEGIN 
        SELECT * FROM customers WHERE first_name = f_name 
        AND last_name = l_name; 
    END $$
DELIMITER;

CALL find_customer("RUHUL","AMIN");