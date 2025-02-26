# 코드를 작성해주세요
import math

M = int(input())
N = int(input())

m = math.ceil(math.sqrt(M))
n = math.floor(math.sqrt(N))

if m >= n: 
    print(-1)
else:
    min = m ** 2
    sum = min
    for i in range(m + 1, n + 1):
        sum += (i ** 2)

    print(sum)
    print(min)