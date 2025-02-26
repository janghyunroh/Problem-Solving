import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    p = int(input())
    mx_price = 0
    mx_player = ''
    
    for _ in range(p):
        data = input().split()
        price = int(data[0])
        player = data[1]
        
        if mx_price < price:
            mx_price = price
            mx_player = player
    
    print(mx_player)
    