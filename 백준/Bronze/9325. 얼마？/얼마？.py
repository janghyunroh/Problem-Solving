import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    sum = 0
    s = int(input())
    sum += s
    
    n = int(input())
    for _ in range(n):
        q, p = map(int, input().split())
        sum += q * p
        
    print(sum)
        
    