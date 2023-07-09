Find all courses that were offered at most once in 2017 as follows : 

When the question says atmost that time we will use DISTINCT clause in 
MySQL.

Ans : SELECT DISTINCT T.course_id FROM Courses AS T 
        WHERE T.course_id IN(
            SELECT R.course_id FROM Section AS R
            WHERE T.course_id = R.course_id
            AND R.year = 2017
        )