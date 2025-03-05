import sys
input = sys.stdin.readline

N = int(input())

for i in range(N):
    for _ in range(i + 1): 
        print('*', end='')
    print('')

for i in range(N - 1):
    for _ in range(N - 1 - i):
        print('*', end='')
    print('')