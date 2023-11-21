    USE studentinfo;
    GO

    -- 增加数据
    INSERT INTO student(sno, sname, classno, sbirthday, ssex)
    VALUES ('2022212083', 'XYZ', '2220704', '2004-05-18', '女'),
        ('2022212080', 'XYZ', '2220704', '2004-05-18', '女'),
        ('2022212081', 'XYZ', '2220704', '2004-05-18', '女'),
        ('2022212082', 'XYZ', '2220704', '2004-05-18', '女');

    -- 删除数据
    DELETE FROM student
    WHERE sno = '2022212083';

    -- 修改数据
    UPDATE student
    SET sname = 'ABC'
    WHERE sno = '2022212080';

    -- 查看数据
    SELECT * FROM student;
    GO