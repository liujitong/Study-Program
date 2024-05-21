# Qt6 Cmake编译MySql驱动、连接Mysql数据库教程

众所周知，自Qt5.7以后，Qt官方已经不再提供MySQL驱动，而是转向了MariaDB。但是，对于一些项目，可能还是需要使用MySQL，这时候就需要自己编译MySQL驱动了。

当使用Cmake出现如下报错：`QSqldatabase: No Such file and directory`。这种情况其实是跟CmakeList里面里面添加SQL模块有关，需要在CmakeList里面添加SQL模块。

## 在Cmake中添加SQL模块

首先打开CmakeList.txt文件，添加如下代码：

```cmake
find_package(Qt NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)
```

接下来在CmakeList.txt文件中添加如下代码：

注意`${PROJECT_NAME}`是您的项目名称，请将其替换为您的项目名称。

```cmake
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
```

## 编译MySQL驱动

在完成上述步骤后，如果你没有MYSQL驱动的话，你在编译的时候会在应用程序输出那里看到：

```error
QSqlDatabase: QMYSQL driver not loaded
QSqlDatabase: available drivers: xxxx
```

前提说明：我的MYSQL服务端是部署于服务器上的，但是对于本地开发时，本地是MYSQL服务端是否适用于本教程，我没有测试过，但是我认为应该是可以的。

### 下载MySQL驱动

进入到MySQL官网下载MySQL驱动，进入到[MySQL官网下载页面](https://dev.mysql.com/downloads/)，找到[MySQL Community Server](https://dev.mysql.com/downloads/mysql/)，点击Archives.

![1716132307703](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716132307703.png)

找到自己的服务端版本，我使用的是8.0.35版本

![1716132349164](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716132349164.png)

找到ZIP Archive，点击下载

![1716132451724](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716132451724.png)

下载完成后，解压到一个文件夹下，并记住这个文件夹的路径。

### 编译MySQL驱动

解压完成之后呢，我们找到Qt的安装目录，使用maintenance tool打开，添加删除组件，下载sources源码。

![1716133095626](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716133095626.png)

记下来在Qt的安装目录下找到源码(src)文件夹,在Qt creator中打开项目，找到src->qtbase->src->plugins->sqldrivers的cmakelist.txt文件，打开。

在Cmake Modules中找到`.cmake.conf`文件，打开，修改

![1716133532668](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716133532668.png)

```cmake
set(feature_sql_mysql ON)
set(MYSQL_INCLUDE_DIR "路径/include")
set(MYSQL_LIBRARY "路径/lib/libmysql/lib")
```

注意修改为你自己的路径。设置完成之后，点击左下角小锤子，等待进度条跑完。

接着在Src->qtbase->src->plugins->build-xxx->plugins->sqldrivers中找到.debug和.dll文件。

![1716133894752](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716133894752.png)

接下来把这两个文件粘贴在mingw_64->plugins->sqldrivers中。

![1716134195444](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716134195444.png)

之后再把下载的mysql.dll和lib放在mingw_64->bin中。

![1716134373910](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716134373910.png)
![1716134411286](https://www.mlxkj.xyz/usr/uploads/Qt6Cmake编译MySql驱动、连接Mysql数据库教程/1716134411286.png)

### 高版本mysql的依赖问题

如果你的mysql版本比较高，可能会出现依赖问题，可以使用[dependencies](https://github.com/lucasg/Dependencies/releases)，并去网上搜索libmysql.dll的依赖库，然后把依赖库放在mingw_64->bin中。
