

SELECT DATE_ADD("2019-07-27", INTERVAL -30 DAY)  AS 'Start_Date'

-- Result ---
| Start_Date |
| ---------- |
| 2019-06-27 |
--------------



SELECT DATE_ADD("2019-07-27", INTERVAL +30 DAY) AS 'End_Date'
-- Result --
| End_Date   |
| ---------- |
| 2019-08-26 |
---------------


Example : 

SELECT 
activity_date AS 'day',
COUNT(DISTINCT user_id) AS 'active_users'
FROM Activity
WHERE
activity_date BETWEEN
DATE_ADD("2019-07-27", INTERVAL - 29 DAY)
AND "2019-07-27"
GROUP BY activity_date;