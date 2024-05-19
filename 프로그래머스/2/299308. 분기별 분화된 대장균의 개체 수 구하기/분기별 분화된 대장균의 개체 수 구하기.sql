-- 코드를 작성해주세요

with p as (select 
           case 
           when Month(DIFFERENTIATION_DATE) between 1 and 3 then '1Q' 
           when Month(DIFFERENTIATION_DATE) between 4 and 6 then '2Q' 
           when Month(DIFFERENTIATION_DATE) between 7 and 9 then '3Q' 
           else '4Q'
           end as QUARTER from ECOLI_DATA
)

select QUARTER, count(QUARTER) as ECOLI_COUNT from p group by QUARTER order by QUARTER;
