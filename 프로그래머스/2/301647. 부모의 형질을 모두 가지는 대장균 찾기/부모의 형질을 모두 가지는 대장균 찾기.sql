-- 코드를 작성해주세요

select c.ID, c.GENOTYPE, cc.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA  c, ECOLI_DATA cc where (c.PARENT_ID is not null and c.PARENT_ID = cc.id and cc.GENOTYPE & c.GENOTYPE = cc.GENOTYPE) order by c.id;