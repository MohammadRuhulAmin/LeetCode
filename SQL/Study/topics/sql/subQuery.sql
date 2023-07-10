SELECT * FROM Trips,(SELECT COUNT(*) FROM Trips)AS ctn



CREATE TABLE Seat (
  id INT,
  student VARCHAR(255)
);

INSERT INTO Seat (id, student) VALUES ('1', 'Abbot');
INSERT INTO Seat (id, student) VALUES ('2', 'Doris');
INSERT INTO Seat (id, student) VALUES ('3', 'Emerson');
INSERT INTO Seat (id, student) VALUES ('4', 'Green');
INSERT INTO Seat (id, student) VALUES ('5', 'Jeames');


SELECT ( CASE
            WHEN id%2 != 0 AND id != counts THEN id+1
            WHEN id%2 != 0 AND id = counts THEN id
            ELSE id-1
        END) AS id, student
FROM seat, (select count(*) as counts from seat)AS seat_counts ,
(SELECT COUNT(*) as c FROM Seat where id%2 = 0)AS cx
ORDER BY id DESC


-- in this query dont do '' quotation in alias , it will give error!