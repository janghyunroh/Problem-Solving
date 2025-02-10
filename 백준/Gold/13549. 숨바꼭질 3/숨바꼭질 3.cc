#include <iostream>
#include <deque>
#include <vector>
#define INF 100000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;

    vector<int> dist(100001, INF);
    dist[N] = 0;

    deque<pair<int, int>> dq;
    dq.emplace_front(N, dist[N]);
    while(dq.size()) {
        auto[cur, cost] = dq.front(); dq.pop_front();
        int tp = cur * 2;
        int ml = cur - 1;
        int mr = cur + 1;

        //teleport
        if(tp >= 0 && tp <= 100000 && dist[tp] > dist[cur]) {
            dist[tp] = dist[cur];
            dq.emplace_front(tp, dist[tp]);
        }

        //move left
        if(ml >= 0 && ml <= 100000 && dist[ml] > dist[cur] + 1) {
            dist[ml] = dist[cur] + 1;
            dq.emplace_back(ml, dist[ml]);
        }

        //move right
        if(mr >= 0 && mr <= 100000 && dist[mr] > dist[cur] + 1) {
            dist[mr] = dist[cur] + 1;
            dq.emplace_back(mr, dist[mr]);
        }
    }

    cout << dist[K];
    return 0;

}