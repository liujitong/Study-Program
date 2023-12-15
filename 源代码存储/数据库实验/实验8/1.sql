USE studentinfo
--设计一个无参数的存储过程proc1，该存储过程的功能是查出所有学生的学号，姓名和班级信息。
GO
CREATE PROCEDURE proc1 
AS
SELECT * FROM student 
GO
--写出一条执行存储过程proc1的语句。
EXEC proc1
GO
--设计一个有参数的存储过程proc2，该存储过程的功能是根据学生的学号修改学生姓名。
GO
CREATE PROCEDURE proc2
@id char(10),
@name VARCHAR(20)
AS
UPDATE student SET sname = @name WHERE sno = @id
GO
EXEC proc2 'B222','张九'
GO
--创建一个有参数的存储过程proc3，该存储过程的功能是根据学生的学号，查找他的平均成绩。（要求用传出参数实现）
GO
CREATE PROCEDURE proc3
@id char(10),
@avg float OUTPUT
AS
SELECT @avg = AVG(sscore) FROM score WHERE sno = @id
GO
--执行部分
DECLARE @avg float
EXEC proc3 'B222',@avg OUTPUT
SELECT @avg AS '平均分';


