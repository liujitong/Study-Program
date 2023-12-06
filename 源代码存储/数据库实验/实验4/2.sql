use studentinfo;
GO

SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO
--1）	创建包含课程号，课程名及课程成绩的视图
CREATE VIEW [dbo].[view1]
AS
SELECT dbo.course.cno, dbo.course.cname, dbo.score.sscore
FROM dbo.course INNER JOIN
dbo.score ON dbo.course.cno = dbo.score.cno

GO
--2）	创建学号，姓名，年龄的视图
CREATE VIEW [dbo].[view2]
AS
SELECT dbo.student.sno, dbo.student.sname, (DATEDIFF(yy,student.sbirthday,GETDATE())) AS sage
FROM dbo.student

GO
--3）	修改2）创建的视图为学号，姓名，年龄，性别的视图
ALTER VIEW [dbo].[view2]
AS
SELECT s.sno, s.sname, (DATEDIFF(yy, s.sbirthday, GETDATE())) AS sage, s.ssex
FROM dbo.student AS s
GO
--4）	创建合适视图（把学生表，课程表，成绩表连接起来）,
CREATE VIEW [dbo].[view3]
AS
SELECT dbo.student.sno, dbo.student.sname, dbo.student.ssex, dbo.student.sbirthday, dbo.course.cno, dbo.course.cname, dbo.course.credit, dbo.score.sscore
FROM dbo.course INNER JOIN
dbo.score ON dbo.course.cno = dbo.score.cno INNER JOIN
dbo.student ON dbo.score.sno = dbo.student.sno
          GO
--5）	在4）的基础上，再次完成如下查询
--①	查询某学号已知的学生的所有课程的课程号，课程名，学分和成绩
SELECT sname,cno, cname, credit, sscore
FROM view3
WHERE sno='2022212080'
--②查出所有的“高级语言程序设计”课程的不及格学生的学号（因为表的限制改为了C语言成绩为60的人）
SELECT sno
FROM view3
WHERE cname='C语言' AND sscore=70
-- 6）	给student表在sno（学号）上建立聚集索引
CREATE CLUSTERED INDEX [sno] ON [dbo].[student]
(
    [sno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF)
GO
--7）	给视图创建索引
CREATE VIEW [dbo].[view4] with schemabinding
AS
SELECT dbo.student.sno, dbo.student.sname, dbo.student.ssex, dbo.student.sbirthday, dbo.course.cno, dbo.course.cname, dbo.course.credit, dbo.score.sscore
FROM dbo.course INNER JOIN
dbo.score ON dbo.course.cno = dbo.score.cno INNER JOIN
dbo.student ON dbo.score.sno = dbo.student.sno
          GO


CREATE UNIQUE CLUSTERED INDEX [INDEXsc] ON [dbo].[view4]
(
	[sno] ASC,
	[cno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF)

--查看NorthWind数据库中的索引情况
use NorthWind
GO
exec sp_helpindex orders   
exec sp_helpindex products
exec sp_helpindex customers

