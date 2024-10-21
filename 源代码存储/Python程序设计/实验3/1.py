# 一个四位数，各位数字互不相同，所有数字之和等于6，并且这个数是11的倍数。满足这种要求的四位数有多少个？各是什么？
count = 0
result = []
for i in range(1000, 10000):
    if i % 11 == 0:
        a = i // 1000
        b = i // 100 % 10
        c = i // 10 % 10
        d = i % 10
        if a + b + c + d == 6 and len(set([a, b, c, d])) == 4:
            count += 1
            result.append(i)
print(count)
print(result)
