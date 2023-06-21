Question 1 : 
Table : 
| p1 | p2 |
| -- | -- | 
| 4  | 1  |
| 3  | 1  | 
| 4  | 3  | 
| 1  | 3  |
| 3  | 4  |
| 1  | 4  |

Output:

| p1 | p2 |
| -- | -- |
| 4  | 1  |
| 1  | 4  |

Solution Query : 
SELECT p1, p2
FROM your_table
WHERE p1 NOT IN (SELECT p2 FROM your_table) OR p2 NOT IN (SELECT p1 FROM your_table);


