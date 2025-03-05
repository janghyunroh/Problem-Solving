import sys
input = sys.stdin.readline

N = int(input())
for _ in range(9):
    n = int(input())
    N -= n
print(N)