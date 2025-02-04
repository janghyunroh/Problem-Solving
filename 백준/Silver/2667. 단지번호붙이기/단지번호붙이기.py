num_of_complex = 0
num_of_houses = []
board = []
visit = []

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(x, y):
    visit[x][y] = True
    sum = 1
    for _ in range(4):
        nx = x + dx[_]
        ny = y + dy[_]

        if 0 <= nx < N and 0 <= ny < N:
            if not visit[nx][ny] and board[nx][ny] == 1:
                sum += dfs(nx, ny)

    return sum


def count_complex():
    for i in range(N):
        for j in range(N):
            if board[i][j] != 0 and not visit[i][j]:
                global num_of_complex
                global num_of_houses

                num_of_houses.append(dfs(i, j))
                num_of_complex += 1


N = int(input())
for _ in range(N):
    li = list(map(int, input()))
    board.append(li)
    li = []
    for __ in range(N):
        li.append(False)
    visit.append(li)

count_complex()
num_of_houses.sort()
print(num_of_complex)
for _ in num_of_houses:
    print(_)



