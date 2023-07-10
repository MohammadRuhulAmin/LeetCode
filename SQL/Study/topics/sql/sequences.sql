A sequence is a user created database object that can be shared by multiple users to generate integers.
tutorial link : https://www.youtube.com/watch?v=EDZMYBNj7wM&list=PLxCzCOWd7aiHqU4HKL7-SITyuSIcD93id&index=25

Step 1 : 

CREATE TABLE sequence_table (
  sequence_name VARCHAR(50) NOT NULL PRIMARY KEY,
  sequence_value INT UNSIGNED NOT NULL
);

Step 2 : 

INSERT INTO sequence_table (sequence_name, sequence_value)
VALUES ('my_sequence', 0);



Step 3 :

DELIMITER //

CREATE PROCEDURE next_sequence_value(IN sequence_name VARCHAR(50), OUT next_value INT)
BEGIN
  START TRANSACTION;
  SELECT sequence_value INTO next_value
  FROM sequence_table
  WHERE sequence_name = sequence_name
  FOR UPDATE;

  UPDATE sequence_table
  SET sequence_value = sequence_value + 1
  WHERE sequence_name = sequence_name;

  COMMIT;
END //

DELIMITER ;





CALL next_sequence_value('my_sequence', @next_value);
SELECT @next_value;
