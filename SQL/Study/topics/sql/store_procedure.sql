DELIMITER $$
CREATE PROCEDURE find_app_idv(IN id INT)
BEGIN
    SELECT * FROM application_reports 
    WHERE application_id = id;
END $$
DELIMITER ;

CALL find_app_idv(166);



DROP PROCEDURE find_app_idv;