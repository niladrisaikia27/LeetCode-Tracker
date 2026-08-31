# Write your MySQL query statement below
SELECT x, y, z,
CASE 
    WHEN x + y > z AND z>x AND z>y THEN 'Yes'
    WHEN x + z > y AND y>x AND y>z THEN 'Yes'
    WHEN y + z > x AND x>y AND x>z THEN 'Yes'
    WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
    ELSE 'No'
END AS triangle
FROM Triangle;