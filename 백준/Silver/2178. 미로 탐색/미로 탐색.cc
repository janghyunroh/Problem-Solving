#include <iostream>
#include <queue>

using namespace std;

int N, M;
int**map;
string input;
bool**visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void BFS() {
    visited[1][1] = true;
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {1, 1}});

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cost = q.front().first;

        q.pop();

        if(x == N && y == M) {
            cout << cost << "\n";
            return;
        }

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(visited[nx][ny] || map[nx][ny] == 0) continue;

            //
            visited[nx][ny] = true;
            q.push({cost + 1, {nx, ny}});
        }
    }

    //
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    map = new int*[N + 1];
    visited = new bool*[N + 1];
    for(int i = 1; i <= N; i++) {
        map[i] = new int[M + 1];
        visited[i] = new bool[M + 1]{false, };
        cin >> input;
        for(int j = 1; j <= M; j++) {
            map[i][j] = input[j - 1] - '0';
        }
    }

    BFS();

    return 0;
}