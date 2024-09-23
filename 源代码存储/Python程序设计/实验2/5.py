
rabbits = [1, 1]

for i in range(2, 24):
    rabbits.append(rabbits[-1] + rabbits[-2])
print(rabbits)
