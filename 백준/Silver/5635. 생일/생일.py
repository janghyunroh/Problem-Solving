import sys
input = sys.stdin.readline

n = int(input())

mx = ''
mx_birth = 99999999
mn = ''
mn_birth = 0

for _ in range(n):
    data = input().split()
    y = data[3]
    m = data[2] if len(data[2]) == 2 else '0' + data[2]
    d = data[1] if len(data[1]) == 2 else '0' + data[1]
    
    birth = int(y + m + d)
    # print(data[0] + ': ', birth)
    
    if mx_birth > birth:
        mx_birth = birth
        mx = data[0]
    
    if mn_birth < birth:
        mn_birth = birth
        mn = data[0]
    
print(mn)
print(mx)
    
    