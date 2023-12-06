use studentinfo;
--查询指定学号的学生的所有课程的课程号，成绩。
SELECT cno,sscore
FROM score
WHERE sno = '201620130101';
--查出所有学生的学号，姓名，选课名称及成绩。
SELECT student.sno,sname,cname,sscore
FROM course,score,student
WHERE student.sno=score.sno AND score.cno=course.cno
--查出所有有“大学英语一”成绩的学生姓名。
SELECT sname
FROM student,score,course
WHERE student.sno=score.sno AND score.cno=course.cno AND cname='大学英语一'
--查询学号为“201720130106”的学生的所有课程的课程号，课程名，学分和成绩。
--  采用连接查询实现。
SELECT course.cno,cname,credit,sscore
FROM course,score
WHERE course.cno=score.cno AND sno='2022212080'
--  采用子查询
SELECT course.cno, course.cname, course.credit, score.sscore  
FROM course  
JOIN score ON course.cno = score.cno  
WHERE score.sno = '2022212080';
--查出所有的“高级语言程序设计”课程的不及格学生的学号。
SELECT sno
FROM score,course
WHERE (score.cno=course.cno) AND (sscore<=60) AND (course.cname='高级语言程序设计')
--查询所有比“201720130106”同学年龄小的学生信息。
SELECT student.*
FROM student
WHERE sbirthday < (SELECT sbirthday FROM student WHERE sno='2022212080')
--统计“吴清豪”同学的平均成绩。
SELECT SUM(sscore)/COUNT(sscore) as '平均成绩'
FROM score,student
WHERE score.sno=(SELECT sno FROM student WHERE sname='吴清豪')
--查出所有平均成绩比“吴清豪”同学的高的学生信息。
SELECT student.*
FROM student, score
WHERE student.sno = score.sno
GROUP BY student.sno,student.sname,student.classno,student.sbirthday,student.ssex
HAVING AVG(score.sscore) > (SELECT AVG(sscore) FROM score WHERE sno = (SELECT sno FROM student WHERE sname = '吴清豪'));
--统计“数据库”课程的平均成绩。
SELECT AVG(sscore) as '平均分'
FROM score
WHERE score.cno=(SELECT cno FROM course WHERE cname='数据库') 
--统计所有“数据库”课程成绩比“数据库”课程的平均成绩高的所有学生名单。
SELECT student.sname
FROM student, score, course
WHERE student.sno = score.sno
AND score.cno = course.cno
AND course.cname = '数据库'
GROUP BY student.sno, student.sname
HAVING AVG(score.sscore) > (SELECT AVG(sscore) FROM score WHERE cno = (SELECT cno FROM course WHERE cname = '数据库'));
--统计所有“数据库”课程成绩比“数据库”课程的平均成绩低的所有学生名单。
SELECT student.sname
FROM student, score, course
WHERE student.sno = score.sno
AND score.cno = course.cno
AND course.cname = '数据库'
GROUP BY student.sno, student.sname
HAVING AVG(score.sscore) < (SELECT AVG(sscore) FROM score WHERE cno = (SELECT cno FROM course WHERE cname = '数据库'));
--查出所有没有“大学英语一”成绩的学生名单。
SELECT student.sname
FROM student
WHERE student.sno NOT IN (SELECT sno FROM score WHERE cno = (SELECT cno FROM course WHERE cname = '大学英语一'));


