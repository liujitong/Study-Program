--建DDL触发器，禁止修改和删除当前数据库中的任何视图
GO
CREATE TRIGGER [trg_view]
ON DATABASE
FOR ALTER_VIEW, DROP_VIEW
AS
BEGIN
    PRINT '禁止修改和删除当前数据库中的任何视图'
    ROLLBACK
END
GO
--创建一个触发器，当向student表中插入新数据时能自动列出所有的同学信息
GO
CREATE TRIGGER [trg_student]
ON student
FOR INSERT
AS
BEGIN
    PRINT '列出所有的同学信息'
    SELECT * FROM student
END
GO

INSERT INTO student VALUES('B323','张三','22022','1999-01-01','男')
--利用inserted和deleted表，设计触发器实现当在课程表中删除某课程时，在成绩表中的成绩记录也全部删除。涉及表：score(成绩表)，course(课程表)
GO
CREATE TRIGGER [trg_course]
ON course
FOR DELETE
AS
BEGIN
    DELETE FROM score WHERE cno IN (SELECT cno FROM deleted)
END
GO
DELETE FROM course WHERE cno = 'C002'
--给成绩表（score）增加一个说明列（explain，varchar(50)）,设计一个触发器，使向成绩表中增加数据和修改数据时，如果成绩为〉=60分，说明列填写‘及格’，其他情况填写’不及格’
GO
ALTER TABLE score ADD explain VARCHAR(10)
GO
CREATE TRIGGER [trg_score]
ON score
FOR INSERT, UPDATE
AS
BEGIN
    UPDATE score SET explain = '及格' WHERE sscore >= 60
    UPDATE score SET explain = '不及格' WHERE sscore < 60
END
GO
INSERT INTO score (cno,sno,sscore) VALUES('C001','B222',80)
UPDATE score SET sscore = 59 WHERE cno = 'C001' AND sno = 'B222'
