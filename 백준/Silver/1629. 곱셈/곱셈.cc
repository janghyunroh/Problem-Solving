#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int A, B, C;

ll solve(ll x, ll y) {
    if(y==0) return 1;
    ll sub = solve(x, y/2);
    ll res =  sub * sub % C;
    if(y % 2) res = res * x % C;   
    return res;

}

int main() {
    cin >> A >> B >> C;
    cout << solve(A, B);
}