-- 코드를 작성해주세요

WITH RECURSIVE ECOLI_TREE as 
(
    -- 초기조건
    select id, parent_id, 1 as generation from ECOLI_DATA where PARENT_ID is null
    UNION ALL
    -- 재귀 조건
    select ed.id, ed.parent_id, et.generation+1 generation from ECOLI_DATA ed
    INNER JOIN ECOLI_TREE et on ed.parent_id = et.id where et.generation < 5
)

select id from ECOLI_TREE et where et.generation = 3 order by id;