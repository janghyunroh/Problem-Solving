#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N, M, R;

vector<vector<int>> graph;
vector<int> visitOrder;
int curOrder = 1;

void dfs(int curNode) {
    visitOrder[curNode] = curOrder;
    //cout << curNode << "의 방문 순서: " << curOrder << "로 지정\n";
    curOrder++;
    for(int i = 0; i < graph[curNode].size(); i++) {
        int nxtNode = graph[curNode][i];
        if(visitOrder[nxtNode] == 0) {
            dfs(nxtNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> R;
    graph.resize(N+1);
    visitOrder.resize(N+1, 0);
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //정점 번호를 오름차순으로 방문한다는 조건을 위해 각 인접리스트를 정렬
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(R);
    
    for(int i = 1; i <= N; i++) cout << visitOrder[i] << '\n';
    
    return 0;
        
}