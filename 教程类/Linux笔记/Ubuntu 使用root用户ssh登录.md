# Ubuntu使用root用户ssh登录

测试版本：Ubuntu 22.04LTS

## 安装openssh-server

```bash
sudo apt install openssh-server
```

## 设置root用户密码

```bash
sudo passwd root
```

## 修改sshd_config文件

```bash
sudo vim /etc/ssh/sshd_config
```

使用vim编辑器打开sshd_config文件，找到PermitRootLogii这一行，将改为yes，保存并退出。并将前后共几行的内容改成如下所示：

```bash
 LoginGraceTime 2m
 PermitRootLogin yes
 StrictModes yes
 #MaxAuthTries 6
 #MaxSessions 10
```

## 重启ssh服务

```bash
sudo service ssh restart
```
