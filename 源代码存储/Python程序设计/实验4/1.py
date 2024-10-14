def menu():
  print('''\n欢迎使用PYTHON学生通讯录
1：添加学生
2：删除学生
3：修改学生信息
4：搜索学生
5：显示全部学生信息
6：退出并保存''')
  
dic = {'张自强': ['12652141777', '材料'], '庚同硕': ['14388240417', '自动化'], '王岩': ['11277291473', '文法']}

def modify_student_info():
  name = input("请输入要修改的学生姓名: ")
  if name in dic:
    phone = input("请输入新的电话: ")
    college = input("请输入新的学院: ")
    dic[name] = [phone, college]
    print("Success")
  else:
    print("No Record")
  print("操作后的字典数据: ", dic)

def main():
  print("字典原始数据: ", dic)
  menu()
  choice = input("请输入您的选择: ")
  if choice == '3':
    modify_student_info()
  else:
    print("ERROR")

if __name__ == "__main__":
  main()