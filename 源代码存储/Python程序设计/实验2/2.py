

hours = eval(input("请输入员工的工作时数："))
if hours > 120:
    salary = 120 * 80 + (hours - 120) * 80 * 1.15
elif hours < 60:
    salary = hours * 80 - 700
else:
    salary = hours * 80

print("员工的应发工资为：%.2f" % salary)
