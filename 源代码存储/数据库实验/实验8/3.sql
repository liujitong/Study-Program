--5）创建新表 logstudent（logid，operationtype，logdate）--日志（学号，操作类型，日志时间），创建触发器，完成如下功能：当针对学生表进行操作（增，删，改）时，在日志表中记录下增删改的学生记录的学号，操作类型（增加，删除，修改），日志时间（操作时间）
CREATE TABLE logstudent(
    logid char(10),
    operationtype VARCHAR(10),
    logdate DATETIME
)
GO
CREATE TRIGGER [trg_logstudent]
ON student
AFTER INSERT, DELETE, UPDATE
AS
BEGIN
    IF EXISTS(SELECT * FROM inserted)
    BEGIN
        INSERT INTO logstudent VALUES((SELECT sno FROM inserted),'增加',GETDATE())
    END
    IF EXISTS(SELECT * FROM deleted)
    BEGIN
        INSERT INTO logstudent VALUES((SELECT sno FROM deleted),'删除',GETDATE())
    END
    IF EXISTS(SELECT * FROM inserted) AND EXISTS(SELECT * FROM deleted)
    BEGIN
        INSERT INTO logstudent VALUES((SELECT sno FROM inserted),'修改',GETDATE())
    END
END
GO
--测试
INSERT INTO student VALUES('B323','张三','22022','1999-01-01','男')
UPDATE student SET sname = '张三' WHERE sno = 'B323'
DELETE FROM student WHERE sno = 'B323'
SELECT * FROM logstudent