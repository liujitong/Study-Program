use studentinfo;
--查询student表的所有学生的学号和姓名，要求查询结果的格式如下所示。学号为：202110020113，姓名为杨莹滢,T-SQL:
DECLARE @sno char(12),@sname char(10);
DECLARE c CURSOR
FOR
SELECT sno,sname FROM student;
OPEN c;
FETCH NEXT FROM c INTO @sno,@sname;
WHILE @@FETCH_STATUS=0
BEGIN
PRINT '学号为：'+@sno+',姓名为'+@sname;
FETCH NEXT FROM c INTO @sno,@sname;
END
CLOSE c;
DEALLOCATE c;
--从student表中查询姓名为“王红”的学生信息，如能查到，则查询出该学生的详细信息，如不能查到，则输出“不存在该姓名的学生”。
IF EXISTS ( select sname from student where sname='liuzhiu')
SELECT *FROM student WHERE sname ='liuzhiu'
ELSE
print ('不存在该姓名的学生');
--创建数据表tmp（tmpid，tmp1,tmp2），其中tmpid为自增列，使用循环自动向数据表中增加10000条记录，要求结果如下：
CREATE TABLE tmp
(	Tmpid int ,
	tmp1  char(5),
	tmp2  char(5)
)
DECLARE @i int=1;
WHILE @i<=10000
BEGIN
INSERT INTO tmp(Tmpid,tmp1,tmp2) VALUES(@i,'a'+CAST(@i AS char),'b'+CAST(@i AS char));
SET @i=@i+1;
END
SELECT *FROM tmp;
--假设有如下规定：2120701班的学生成绩存入score2120701（sno,cno,score）,2120702班的学生数据存入score2120702（sno,cno,score），请根据新增加的数据情况创建所需表，如果对应的表已经存在则不做处理，如对应的表不存在则创建数据表。
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='score2120701')
CREATE TABLE score2120701
(	sno char(12),
    cno char(12),
    score int
)
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='score2120702')
CREATE TABLE score2120702
(	sno char(12),
    cno char(12),
    score int
)
--设计一个函数，功能为可以根据班级编号(classno)查出该班级的人数。
GO
CREATE FUNCTION f_classno(@classno char(12))
RETURNS int
AS
BEGIN
DECLARE @count int;
SELECT @count=COUNT(*) FROM student WHERE classno=@classno;
RETURN @count;
END
GO
SELECT dbo.f_classno('2120701');
--设计一个函数，根据借书证号和图书编号判断该图书是否超期，并返回违约金，如果未超期，违约金为0，如果超期，每超期一天收费1角。（借书信息表（借书证号，图书编号,借书日期，还书日期））
--表格
create table bomannage(
carid char(5),
bookid char(5),
bodate datetime,
redate datetime
)
insert into bomannage(carid,bookid,bodate) values('00001','A0001','2022-4-30')
insert into bomannage(carid,bookid,bodate) values('00002','A0002','2022-3-30')
--假设期限为14天
GO
CREATE FUNCTION f_book(@carid char(5),@bookid char(5))
RETURNS int
AS
BEGIN
DECLARE @money int;
DECLARE @day int;
SELECT @day=DATEDIFF(day,bodate,redate) FROM bomannage WHERE carid=@carid AND bookid=@bookid;
IF @day>14
SET @money=@day*0.1;
ELSE
SET @money=0;
RETURN @money;
END
GO
UPDATE bomannage SET redate='2022-5-13' WHERE carid='00001' AND bookid='A0001';

SELECT dbo.f_book('00001','A0001');
--7）从学生表中随机调出指定个数的学生数据，比如输入参数5，则调出随机5个学生的数据。参考函数: SELECT TOP 10 *  FROM student order by NEWID() 可以实现从student表中查出随机5条学生数据，也可以自己采用算法实现此功能。
DECLARE @NumStudents INT = 2;  
  
SELECT TOP (@NumStudents) *  
FROM student  
ORDER BY NEWID();
--查询学生表中所有的学生姓，并取消重复值。（做完后可继续查询出每个姓的学生人数）
SELECT DISTINCT LEFT(sname,1) FROM student;
--查询学生表中所有姓“王”的学生的学号和姓名。
SELECT sno,sname FROM student WHERE sname LIKE '王%';