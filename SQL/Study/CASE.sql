SELECT Column1,Column2
CASE 
    WHEN Condition1 THEN result1
    WHEN Condition2 THEN result2
    WHEN Condition3 THEN result3
    WHEN Condition4 THEN result4
END AS Alias
FROM TableName

Example: 
SELECT id, student_name, num,
    CASE
        WHEN num >= 80 AND num <= 100 THEN 'A+'
        WHEN num >= 70 AND num <= 79 THEN 'A'
        WHEN num >= 59 AND num <= 69 THEN 'A-'
        ELSE 'Golden A+'
    END AS Grade
FROM Marksheet;
