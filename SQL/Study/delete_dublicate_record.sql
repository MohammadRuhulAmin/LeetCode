year    gass    lng 
2016-17	972.00	0.00
2017-18	961.00	0.00
2018-19	965.00	116.00
2019-20	887.00	203.00
2020-21	892.76	216.10
2021-22	842.01	240.56
2021-22	842.01	240.56

i want to delete the last tuple from two dublicate tuple 




DELETE FROM historical_gas_production 
WHERE 
year = '2021-22'
AND 
gas = 842.01 
AND 
lng = 240.56 
LIMIT 1


SELECT *
FROM historical_gas_production hgp
WHERE (hgp.year, hgp.gas, hgp.lng) IN (
    SELECT hgp2.year, hgp2.gas, hgp2.lng
    FROM historical_gas_production hgp2
    WHERE hgp2.year = '2021-22' AND hgp2.gas = 842.01 AND hgp2.lng = 240.56
)
GROUP BY hgp.year, hgp.gas, hgp.lng
HAVING COUNT(*) > 1