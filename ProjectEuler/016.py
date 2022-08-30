num = 2 ** 1000
num_sum = 0

while num != 0:
    num_sum += (num % 10)
    num = num // 10;

print(num_sum)
