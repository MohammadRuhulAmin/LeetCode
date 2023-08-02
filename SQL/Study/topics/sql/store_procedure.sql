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

-- with while loop 

DELIMITER $$
CREATE PROCEDURE loop_examplexx(in rangex int)
BEGIN
    DECLARE counter INT DEFAULT 1;

    WHILE counter <= rangex DO
        SELECT counter;
        SET counter = counter + 1;
    END WHILE;
END $$
DELIMITER ;

call loop_examplexx(12);


-- ANOTHER LOOP 

DELIMITER $$
CREATE PROCEDURE loop_exampleX(IN t_range INT)
BEGIN 
    DECLARE x INT;
    DECLARE str VARCHAR(255);
    
    SET x = 1;
    SET str = '';
    
    loop_label: LOOP
        IF x > t_range THEN
            LEAVE loop_label;
        END IF;
        
        SET x = x + 1;
        SET str = CONCAT(str, x, '.');
    END LOOP;
    
    SELECT str;
END $$
DELIMITER ;


CALL loop_exampleX(10);
