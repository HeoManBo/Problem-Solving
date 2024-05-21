SET @hour := -1;

-- 코드를 입력하세요
SELECT (@hour := @hour + 1) as hour, (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @hour) as COUNT FROM ANIMAL_OUTS where @hour < 23
