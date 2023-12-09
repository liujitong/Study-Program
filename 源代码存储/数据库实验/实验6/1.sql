use studentinfo
CREATE TABLE teacher
(
    tno char(4) PRIMARY KEY,
    tname VARCHAR(20),
    tsex char(2) ,
    tbirthday DATETIME
);
--假设不允许教师出现重名，修改teacher表的定义，给tname字段加上唯一约束。
ALTER TABLE teacher ADD UNIQUE(tname);
-- 给tsex字段绑定默认值‘男’ （默认值规则的关键字是default ）
ALTER TABLE teacher 
ADD CONSTRAINT moren DEFAULT '男' for tsex;
--给tsex字段设置check约束，使tsex字段的取值范围为：‘男’或‘女’
ALTER TABLE teacher
ADD CONSTRAINT sexcheck CHECK(tsex='男' or tsex='女');
--给tno字段增加约束，要求教师编号必须是形如A001,B002这样的形式，即由一个大写字母和3个数字组合而成
ALTER TABLE teacher
ADD CONSTRAINT tnostd CHECK(tno like '[A-Z][0-9][0-9][0-9]');
--删除tsex字段上创建的check约束
ALTER TABLE teacher
DROP CONSTRAINT sexcheck;
--给成绩表（score）创建合适的外键约束,验证外键约束的级联删除和级联更新功能。
ALTER TABLE score
ADD CONSTRAINT FK_score_student
FOREIGN KEY (sno) REFERENCES student(sno)
ON DELETE CASCADE
--验证方法：向成绩表中增加学生表中不存在的学生成绩，或从学生表中删除某有成绩的学生数据。
INSERT INTO score VALUES('S001','C001',90);
DELETE FROM student WHERE sno='S001';
