import turtle as tt  

# 画正面的正方形
tt.forward(150)  # 100 * 1.5
tt.right(90)
tt.forward(150)  # 100 * 1.5
tt.right(90)
tt.forward(150)  # 100 * 1.5
tt.right(90)
tt.forward(150)  # 100 * 1.5

# 画除了正方形之外的实线
tt.right(30)
tt.forward(75)  # 50 * 1.5
tt.right(60)
tt.forward(150)  # 100 * 1.5
tt.right(90)
tt.forward(150)  # 100 * 1.5
tt.right(30)
tt.forward(75)  # 50 * 1.5

tt.up()
tt.goto(150, 0)  # 100 * 1.5
tt.down()
tt.right(180)
tt.forward(75)  # 50 * 1.5

# 画正方体背面的虚线
tt.up()
tt.goto(37.5, 75)  # 25 * 1.5, 50 * 1.5
tt.down()
tt.right(150)

i = 1
while i < 8:
  tt.forward(15)  # 10 * 1.5
  tt.up()
  tt.forward(7.5)  # 5 * 1.5
  tt.down()
  i += 1

tt.right(270)

n = 1
while n < 8:
  tt.forward(15)  # 10 * 1.5
  tt.up()
  tt.forward(7.5)  # 5 * 1.5
  tt.down()
  n += 1

tt.up()
tt.goto(37.5, -75)  # 25 * 1.5, -50 * 1.5
tt.down()
tt.right(120)

m = 1
while m < 5:
  tt.forward(15)  # 10 * 1.5
  tt.up()
  tt.forward(7.5)  # 5 * 1.5
  tt.down()
  m += 1

tt.up()
tt.done()
