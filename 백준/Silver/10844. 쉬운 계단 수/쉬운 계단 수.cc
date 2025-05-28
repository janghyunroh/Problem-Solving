#include <iostream>

using ll = long long;
using namespace std;

int N;
ll dp[101][10];
//dp[i][j]: 길이 i의 j로 끝나는 계단 수의 개수
// 0으로 끝나는 계단 수 개수: 1 짧은 계단 수 중 1로 끝나는 계단 수 개수
// 9로 끝나는 계단 수 개수: 1 짧은 계단 수 중 8로 끝나는 계단 수 개수
// j(1 ~ 8)로 끝나는 계단 수 개수: 1 짧은 계단 수 중 j - 1로 끝나는 개수 + j + 1로 끝나는 개수

// -> 길이 1짜리 계단 수를 채워넣고 길이를 1씩 늘려가며 DP 배열 채우기
  
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll sm = 0;
    cin >> N;
    
    // 길이 1짜리 초기화
    dp[1][0] = 0;
    for(int j = 1; j <= 9; j++) dp[1][j] = 1;
    
    //dp배열 채우기
    for(int i = 2; i <= N; i++) {
        
        //0, 9로 끝나는 계단 수
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        
        //1 ~ 8로 끝나는 계단 수 
        for(int j = 1; j <= 8; j++) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        
    }
    
    //길이 N짜리 계단 수 개수 세기
    for(int j = 0; j <= 9; j++) {
        sm = ((sm + (dp[N][j] % 1000000000)) % 1000000000);
    }
    
    cout << sm;
    return 0;
}
