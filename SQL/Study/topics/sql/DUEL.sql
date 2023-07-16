DUAL is a special one-row, one-column table that exists in some database systems, including Oracle and MySQL. It is commonly 
used as a placeholder table when a table reference is required in a query, but no actual table is needed.

The DUAL table is typically used in scenarios where you need to perform computations or retrieve constant values in a
 query without referencing an actual table. For example, if you want to select the current date or perform arithmetic 
 operations without joining or referencing any specific table, you can use the DUAL table as a dummy table reference.

Here's an example usage of DUAL:


SELECT 'ruhul amin', 'ruhul_@gmail.com', '01322352890', '2023-07-22'
FROM DUAL;


#Python Sample Code !

import mysql.connector

# Establishing the connection
conn = mysql.connector.connect(
   user='root', password='ruhulamin', host='127.0.0.1', database='study')

# Creating a cursor object using the cursor() method
cursor = conn.cursor()
name = 'Ruhul Amin'
email = "ruhul@gmail.com"
contact = "01322352864"
date = "2023-07-19"

# Preparing SQL query to INSERT a record into the database.
sql = f"""
INSERT INTO experiment (name, email, contact, date)
         SELECT '{name}','{email}','{contact}','{date}' FROM DUAL
         WHERE NOT EXISTS(
            SELECT * FROM experiment
            WHERE name = '{name}' AND
            email = '{email}' AND
            contact = '{contact}' AND
            date = '{date}'
         )
"""

try:
   # Executing the SQL command
   cursor.execute(sql)
   print("Data inserted successfully!")
   # Commit your changes in the database
   conn.commit()

except Exception as e:
   # Rolling back in case of error
   print("Error:", e)
   conn.rollback()

# Closing the connection
conn.close()
