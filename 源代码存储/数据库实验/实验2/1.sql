USE studentinfo;
--查找女生--
SELECT * FROM student WHERE ssex LIKE '女' 
--查出student表中的前3条记录。
SELECT TOP 3 *FROM student
--=查出所有的班号及班级信息
SELECT * FROM class WHERE classno IS NOT NULL
--统计2120701班共有多少同学
SELECT COUNT(*) FROM student WHERE classno='2120701'
--统计2120702班共有多少男同学。
SELECT COUNT(*) FROM student WHERE classno='2120702' AND ssex='男'
--请把2120701班的所有学生信息按照姓名降序排序。
SELECT * FROM student WHERE classno='2120701' ORDER BY sname DESC
--查询出所有在1999年1月1日以前出生的学生信息
SELECT * FROM student WHERE sbirthday<'1999-01-01'
--查询出年龄大于18岁的所有学生信息提示 year(字段名)可以获取某日期型字段的年份值) （请给列起别名）
SELECT *,YEAR(GETDATE())-YEAR(sbirthday) AS age FROM student WHERE YEAR(GETDATE())-YEAR(sbirthday)>18
SELECT * FROM student WHERE classno='2120701' AND ssex='男'
UNION
SELECT * FROM student WHERE classno='2120702' AND ssex='男'
SELECT * FROM student WHERE classno IN ('2120701','2120702') AND ssex='男'