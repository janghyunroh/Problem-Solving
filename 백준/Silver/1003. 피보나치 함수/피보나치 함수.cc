#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	int arr[40][2];

	//N = 40까지 미리 구해놓기 (Memoization)
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	cin >> T;

	while (T--) {
		cin >> N;
		cout << arr[N][0] << " " << arr[N][1] << "\n";
	}
}