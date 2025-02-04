#include <iostream>

using namespace std;

// 1. 다리는 겹쳐질 수 없음
// 2. 항상 정확히 서쪽 사이트 개수(N)만큼 지음.

// -> 동쪽 사이트가 정해지면 다리 구조가 결정됨. 즉, 동쪽 M개에서 N개의 사이트를 고르는 경우의 수
// mCn 계산하면 됨.  

// 다만 연산복잡도가 너무 높아 DP 써서 풀기
// nCr = n-1Cr-1 + n-1Cr
// (M-N)C(0) ~ M-NCN
// 그리고 오버플로우 주의할 것

using ll = long long;

int N, M, T;

ll combination(int n, int r) {
    ll dp[31][31];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= r; j++) {
            if( i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}


int main() {
    cin >> T;
    while(T--) {
        cin >> N >> M;
        cout << combination(M, N) << '\n';
    }
}



