import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    cnt = 0
    sum = 0
    N = int(input())
    for _ in range(N):
        c, f = input().split()
        c = int(c)
        f = float(f)
        cnt += c
        sum += f * c
    gpa = sum / cnt
    print(cnt, gpa)