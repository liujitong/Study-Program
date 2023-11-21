--选做题全部
USE studentinfo;
CREATE TABLE course
(
    cno char(4) NOT NULL PRIMARY KEY,
    cmane VARCHAR(20),
    credit FLOAT
);
INSERT INTO course(cno, cname, credit)
VALUES('C001','高级语言程序设计',5),('C002','数据库',4),('C003','大学英语一',5);
SELECT * FROM course;
-- 创建score表
CREATE TABLE score
(
    sno char(12) NOT NULL,
    cno char(4) NOT NULL,
    sscore float NOT NULL,
    PRIMARY KEY (sno, cno)
);
ALTER TABLE score
ADD CONSTRAINT pk_score PRIMARY KEY (sno,cno,score);
-- 插入数据
INSERT INTO score(sno, cno, sscore)
VALUES('201620130101', 'C001', 79),
      ('201620130105', 'C001', 86),
      ('201620130106', 'C002', 75),
      ('201620130107', 'C003', 89);

-- 查询score表
SELECT * FROM score;

