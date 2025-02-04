#include <iostream>
#include <queue>
#define ll long long

using namespace std;

struct absoulute {
    bool operator()(ll a, ll b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    priority_queue<ll, vector<ll>, absoulute> pq;

    while(N--) {
        int x; cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}