import turtle as tt

# 设置初始颜色
tt.fillcolor("yellow")
tt.pencolor("yellow")

# 开始绘制第一个形状
tt.up()
tt.goto(20, 330)  # 绘画
tt.seth(225)
tt.down()
tt.begin_fill()
tt.fd(187.5)      # 绘画
tt.right(90)
tt.fd(75)         # 绘画
tt.right(90)
tt.fd(150)        # 绘画
tt.right(90)
tt.circle(37.5, 90) # 半径绘画
tt.end_fill()

# 开始绘制第二个形状
tt.up()
tt.goto(-60, 285)  # 绘画
tt.seth(-45)
tt.down()
tt.begin_fill()
for i in range(2):
    tt.forward(300)  # 绘画
    tt.right(90)
    tt.forward(45)   # 绘画
    tt.right(90)
tt.end_fill()

# 开始绘制第三个形状
tt.up()
tt.goto(-150, 150)  # 绘画
tt.seth(-50)
tt.down()
tt.begin_fill()
tt.circle(150, 180)  # 半径绘画
tt.fd(30)            # 绘画
tt.right(157)
tt.circle(-172.5, 190) # 
tt.left(90)
tt.fd(30)            # 绘画
tt.right(90)
tt.fd(30)            # 绘画
tt.right(90)
tt.fd(30)            # 绘画
tt.left(80)
tt.fd(45)            # 绘画
tt.end_fill()

# 开始绘制第四个形状
tt.up()
tt.goto(-135, 75)   # 绘画
tt.down()
tt.begin_fill()
tt.circle(30)       # 半径绘画
tt.end_fill()

# 维持面板
tt.done()