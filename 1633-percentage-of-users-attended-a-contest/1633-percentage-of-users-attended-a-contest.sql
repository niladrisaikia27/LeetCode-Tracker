# Write your MySQL query statement below
SELECT contest_id, 
    ROUND((sum * 100)/(SELECT COUNT(*) FROM Users), 
    2) AS percentage FROM (
    SELECT contest_id, COUNT(contest_id) AS sum
    FROM Register
    GROUP BY contest_id
) AS p
GROUP BY p.contest_id
ORDER BY percentage DESC, p.contest_id ASC;
