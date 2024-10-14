# 输入一个嵌套列表，嵌套层次不限，根据层次，求列表元素的加权和。第一层每个元素 的值为：元素值*1，第二层每个元素的值为：元素值*2，第三层每个元素的值为：元素值*3， ...,以此类推！

def sum_list(lst, level=1):
    print(lst, level)
    s = 0
    for i in lst:
        #如果是列表，递归调用
        if isinstance(i, list):
            s += sum_list(i, level+1)
        else:
            s += i * level
    return s
print(sum_list(eval(input())))
