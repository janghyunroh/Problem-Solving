for _ in range(int(input())):
    M, N, x, y = map(int, input().split())

    # k = year number(answer)
    # k = M * (?) + x = N * (?) + y
    # (k - x) % M == 0 and (k - y) % N == 0
    
    # M과 N이 서로소인 경우 유일
    # 서로소가 아니라서 유일하지 않더라도 
    # 작은 수부터 탐색하면 최소 정답 구할 수 있음

    # x를 기준으로 카운팅(둘 중 하나 아무거나 가능)
    k = x   # x 기준 첫 사이클부터 시작
    found = False
    
    while k <= M * N:   #k<=GCD(M,N) 이므로 두 수의 곱보단 항상 작음
        if (k - x) % M == 0 and (k - y) % N == 0: #안 나눠떨어지면 아닌 것
            print(k)
            found = True
            break
        else:
            k = k + M #다음 사이클로 이동

    if not(found):
        print(-1)
