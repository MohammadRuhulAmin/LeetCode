Function Syntax:
DELIMITER $$
CREATE FUNCTION Function_Name(variable_Name datatype) RETURNS datatype
BEGIN
     RETURN data;
END $$
DELIMITER;

DELIMITER $$
CREATE FUNCTION Addition(num1 int,num2 int) RETURNS int
BEGIN
     RETURN num1 + num2;
END $$
DELIMITER;


DELIMITER $$
CREATE FUNCTION ShowName(firstName VARCHAR(50),lastName VARCHAR(50))
RETURNS VARCHAR(100)
BEGIN
     RETURN firstName + ' ' + lastName;
END $$
DELIMITER;