#include <iostream>

using namespace std;

int solve(int X) {
    int cnt = 0;
    for (int i = 7; i >= 0; i--) cnt += ((X >> i) & 1);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int X; cin >> X;
    cout << solve(X);
    return 0;
}
