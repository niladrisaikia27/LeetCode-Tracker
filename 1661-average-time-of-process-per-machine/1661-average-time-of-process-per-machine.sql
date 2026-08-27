# Write your MySQL query statement below
WITH calculateTime AS (
    SELECT machine_id, process_id, activity_type, timestamp,
    LAG(timestamp) OVER(ORDER BY machine_id, process_id, activity_type) AS start
    FROM Activity
),
totalTime AS (
    SELECT machine_id, process_id, activity_type, timestamp, start,
    (timestamp - start) AS total
    FROM calculateTime
    WHERE activity_type = 'end' 
)
SELECT machine_id, ROUND(AVG(total), 3) AS processing_time
FROM totalTime
GROUP BY machine_id;
