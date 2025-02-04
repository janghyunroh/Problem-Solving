//Boj - 9465 스티커

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--) {

        //input
        cin >> n;
        vector<vector<int>> sticker;
        sticker.resize(2, vector<int>(n + 1, 0));
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> sticker[i][j];
            }
        }

        //dp
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for(int i = 0; i <= n; i++) {
            if(i == 0) {
                dp[0][i] = 0;
                dp[1][i] = 0;
            }
            else if(i == 1) {
                dp[0][i] = sticker[0][i];
                dp[1][i] = sticker[1][i];
            }
            else {
                //current score[a][i] + dp[!a][i-1] vs
                //current score[a][i] + max(dp[!a][i - 2], dp[!a][i - 2])
                for(int a = 0; a < 2; a++) {
                    dp[a][i] = max(sticker[a][i] + dp[1 - a][i - 1], 
                    sticker[a][i] + max(dp[1 - a][i - 2], dp[a][i - 2]));
                }
            }
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}