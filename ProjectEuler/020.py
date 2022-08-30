def factorial(num):
    product = 1
    while num != 1:
        product *= num
        num -= 1
    return product

num_sum = 0
fact_100 = factorial(100)
while fact_100 != 0:
    num_sum += (fact_100 % 10)
    fact_100 = fact_100 // 10

print(num_sum)
