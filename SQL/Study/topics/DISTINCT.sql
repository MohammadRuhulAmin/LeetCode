
-- create
CREATE TABLE EMPLOYEE (
  name TEXT NOT NULL,
  dept TEXT NOT NULL
);

-- insert
INSERT INTO EMPLOYEE VALUES ( 'Clark', 'Sales');
INSERT INTO EMPLOYEE VALUES ( 'Clark', 'Sales');
INSERT INTO EMPLOYEE VALUES ( 'Clark', 'Sales');
INSERT INTO EMPLOYEE VALUES ( 'Dave', 'Accounting');
INSERT INTO EMPLOYEE VALUES ( 'Ava', 'Sales');
INSERT INTO EMPLOYEE VALUES ( 'Ava', 'Sales');
INSERT INTO EMPLOYEE VALUES ( 'Ava', 'Sales');
-- fetch 
SELECT DISTINCT * FROM EMPLOYEE ;


it will only select the distinct rows from the table!