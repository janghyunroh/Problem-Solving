#include <iostream>

using namespace std;
using ll = long long;

ll solve(ll n) {
    ll i = 1, max_dist;
    while(true) {
        
        if(i % 2 == 0) max_dist = (i/2) * (i/2) + (i/2);
        else max_dist = ((i+1)/2) * ((i+1)/2);
        
        if(max_dist >= n) return i;
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    ll x, y;

    cin >> T;
    while(T--) {
        cin >> x >> y;
        cout << solve(y - x) << '\n';
    }
    return 0;
}
