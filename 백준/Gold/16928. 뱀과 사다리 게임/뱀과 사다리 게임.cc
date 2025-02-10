#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> ladder(101, 0);
    vector<int> snake(101, 0);
    for(int i=0;i<N;i++) {
        int x, y; cin >> x >> y;
        ladder[x] = y;
    }
    for(int i=0;i<M;i++) {
        int u, v; cin >> u >> v;
        snake[u] = v;
    }


    //BFS
    queue<pair<int, int>> q;
    bool visited[101] = {false, };
    visited[1] = true;
    q.push({1, 0});

    while(q.size()) {
        int cur = q.front().first;
        int cost = q.front().second; q.pop();

        //
        if(cur == 100) {
            cout << cost << "\n";
            break;
        }

        //
        for(int i=1;i<=6;i++) {
            int nxt = cur + i;
            int nxt_cost = cost + 1;
            if(nxt > 100) continue;
            if(visited[nxt]) continue;
            if(ladder[nxt]) {
                nxt = ladder[nxt];
                if(visited[nxt]) continue;

                //
                visited[nxt] = true;
                q.push({nxt, nxt_cost});
            }
            else if(snake[nxt]) {
                nxt = snake[nxt];
                if(visited[nxt]) continue;

                visited[nxt] = true;
                q.push({nxt, nxt_cost});
            }

            else {
                visited[nxt] = true;
                q.push({nxt, nxt_cost});
            }
        }

    }
    return 0;
}