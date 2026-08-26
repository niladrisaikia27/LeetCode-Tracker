# Write your MySQL query statement below
WITH rankedWeather AS(
    SELECT id, recordDate, temperature,
    LAG(recordDate) OVER(ORDER BY recordDate) AS prevDate,
    LAG(temperature) OVER(ORDER BY recordDate) AS prevTemp
    FROM Weather
)
SELECT Id FROM rankedWeather
WHERE DATEDIFF(recordDate, prevDate) = 1 AND temperature > prevTemp;