#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, K;
int visited[100001]{false, };

int bfs() {
    queue<pair<int, int>> q;

    visited[N] = true;
    q.push({N, 0});

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int num = node.first;
        
        if(num == K) {
            return node.second;
        }

        //node - X - 1
        if(num - 1 >= 0 && !visited[num - 1]) {

            visited[num - 1] = true;
            q.push({num - 1, node.second + 1});
        }


        //node - X + 1
        if(num + 1 <= 100000 && !visited[num + 1]) {

            visited[num + 1] = true;
            q.push({num + 1, node.second + 1});
        }


        //node - X * 2
        if(num * 2 <= 100000 && !visited[num * 2]) {

            visited[num * 2] = true;
            q.push({num * 2, node.second + 1});
        }
    }

    //unreachable return - 그럴 일 없음. 
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cout << bfs() << "\n";
    return 0;
}