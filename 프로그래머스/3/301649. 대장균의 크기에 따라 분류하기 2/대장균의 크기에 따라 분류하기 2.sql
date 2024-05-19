WITH p AS (
    SELECT ID,PERCENT_RANK() OVER(ORDER BY SIZE_OF_COLONY DESC) AS per FROM ECOLI_DATA)

select p.ID, case when p.per <= 0.25 then "CRITICAL" 
when p.per <= 0.50 then "HIGH"
when p.per <= 0.75 then "MEDIUM" 
else "LOW"
end as COLONY_NAME from p order by p.id


