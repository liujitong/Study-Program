USE studentinfo;

ALTER TABLE student
ADD sbirthday datetime,
    ssex char(2);

ALTER TABLE student
DROP COLUMN sage;
