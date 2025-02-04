#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<bool>visited(N + 1, false);
    vector<vector<int>>graph(N + 1);
    int **ans = new int*[N + 1];

    for(int i=1;i<=N;i++) {
        ans[i] = new int[N + 1];
        for(int j=1;j<=N;j++) {
            ans[i][j] = 0;
            int a; cin >> a;
            if(a) graph[i].emplace_back(j);
        }
    }

    
    for(int i=1;i<=N;i++) {
        //BFS
        queue<int>q;
        q.push(i);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(int j=0;j<graph[cur].size();j++) {
                int next = graph[cur][j];
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    ans[i][next] = 1;
                }
            }
        }
        for(int j=1;j<=N;j++) visited[j] = false;
    }


    //
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}