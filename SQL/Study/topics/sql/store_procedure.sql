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
        SELECT str;
    END LOOP;
    
    SELECT str;
END $$
DELIMITER ;


CALL loop_exampleX(10);




-- another example 

DELIMITER $$
CREATE PROCEDURE loop_exampleXx(IN t_range INT)
BEGIN 
    DECLARE x INT;
    DECLARE str VARCHAR(255);
    SET x = 1;
    SET str = '';
    -- Create a temporary table to store intermediate results
    CREATE TEMPORARY TABLE IF NOT EXISTS temp_results (
        id INT AUTO_INCREMENT PRIMARY KEY,
        result VARCHAR(255)
    );
    loop_label: LOOP
        IF x > t_range THEN
            LEAVE loop_label;
        END IF;
        SET str = CONCAT(str, x, '.');
        SET x = x + 1;
        -- Insert the intermediate result into the temporary table
        INSERT INTO temp_results (result) VALUES (str);
    END LOOP;
    -- Select the final result from the temporary table
    SELECT GROUP_CONCAT(result SEPARATOR '') AS final_result FROM temp_results;
    -- Drop the temporary table after use
    DROP TEMPORARY TABLE IF EXISTS temp_results;
END $$
DELIMITER ;
