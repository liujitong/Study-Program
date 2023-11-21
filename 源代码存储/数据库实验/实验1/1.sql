CREATE DATABASE [studentinfo]
ON
(
    NAME = N'studentinfo', 
    FILENAME = N'D:\Database_Local\studentinfo.mdf' , 
    SIZE = 10MB  , 
    MAXSIZE = 100MB, 
    FILEGROWTH = 5%
)
LOG ON
    (
        NAME = N'studentinfo_log', 
        FILENAME = N'D:\Database_Local\studentinfo_log.ldf' , 
        SIZE = 2MB , 
        MAXSIZE = 30MB , 
        FILEGROWTH = 1MB
    )
