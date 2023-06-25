SELECT name, GROUP_CONCAT(CONCAT('"', id, '"') ORDER BY id DESC) AS ids
FROM employee
GROUP BY name;


Result : 

+-------+--------------+
| name  |    ids       |
+-------+--------------+
| ruhul | "12","10","8"|
| sakib |   "9","5"    |
+-------+--------------+
