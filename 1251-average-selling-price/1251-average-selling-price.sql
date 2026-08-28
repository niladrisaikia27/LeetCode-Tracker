# Write your MySQL query statement below
WITH total AS (
    SELECT p.product_id, p.price, s.units,
    (p.price * s.units) AS totalPrice
    FROM Prices p
    LEFT JOIN 
    UnitsSold s ON p.product_id = s.product_id AND s.purchase_date BETWEEN p.start_date AND p.end_date
),
totalUnits AS (
    SELECT product_id,
    SUM(totalPrice) AS sum,
    SUM(units) AS totalUnits
    FROM total 
    GROUP BY product_id
),
avgPrice AS (
    SELECT product_id,
    (sum/totalUnits) AS avg
    FROM totalUnits
)
SELECT product_id, IFNULL(ROUND(avg, 2), 0) AS average_price FROM avgPrice;