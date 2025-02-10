#include <iostream>

using namespace std;

int N, K;
int* W, * V;
int** dp;

int main() {
	cin >> N >> K;
	W = new int[N + 1];
	V = new int[N + 1];
	dp = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[K + 1];
	}
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= K; w++) {
			if (i == 0 || w == 0) dp[i][w] = 0;
			else if (W[i] > w) dp[i][w] = dp[i - 1][w];
			else dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - W[i]] + V[i]);
		}
	}

	cout << dp[N][K] << "\n";

}