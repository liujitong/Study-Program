use studentinfo;
INSERT INTO student (sno,sname,classno,sbirthday,ssex)
VALUES(2022212080,'刘纪彤',2220704,'2004-05-17','男');

--2）	使用一条insert语句向学生表中增加学号为：202120210112，姓名为“张三”，性别为’男’的学生记录。
INSERT INTO student (sno,sname,ssex)
VALUES(202120210112,'张三','男');
--3
INSERT INTO student(sno,sname,classno,sbirthday,ssex)
VALUES(202212088,'刘智钰',2220704,'2004-06-18','男'),
(2022212085,'陈振搏',2220704,'2003-05-15','男'),
(2022212101,'刘佳鑫',2220705,'2005-02-21','男');

--4）	修改第2）步增加的学生记录的姓名为“李四”，性别为“女”。
UPDATE student
SET sname='李四',ssex='女'
WHERE sno=202120210112;
--修改第2）步增加的学生记录的出生日期为2004年6月17日
UPDATE student
SET sbirthday='2004-06-17'
WHERE sno=202120210112;

INSERT INTO score(sno,cno,sscore)
VALUES(202120210112,'C001',90),
(201620130101,'C001',79),
(201620130105,'C001',86),
(201620130106,'C002',75),
(201620130107,'C003',89);

--7）	修改学号为：201620130105的C001课程的成绩为90。
UPDATE score
SET sscore=90
WHERE sno=201620130105 AND cno='C001';
--8）	使用delete语句删除掉第2）步所增加的数据。
DELETE FROM student
WHERE sno=202120210112;
--9）	向课程表course中增加一条记录：其中课程号为C110,课程名为：操作系统，学分为5。
INSERT INTO course(cno,cname,credit)
VALUES('C110','操作系统',5);
--自行设计一条成绩记录增加到成绩表score中（insert语句），要求成绩为空。
INSERT INTO score(sno,cno)
VALUES(2022212080,'C110');
--使用delete语句把第10）步的数据删除。
DELETE FROM score
WHERE sno=2022212080 AND cno='C110';
--12) 将张三所选课程的成绩提高10分。
INSERT INTO score(sno,cno,sscore)
VALUES(202120210112,'C003',90);
UPDATE score
SET sscore=sscore+10
WHERE score.sno=(SELECT sno FROM student WHERE sname='张三');
