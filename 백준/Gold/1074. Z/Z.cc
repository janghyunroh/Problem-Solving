#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;

	long long ans = 0;

	while (true) {
		
		//calculating factor 
		long long factor;
		if (r >= 0 && r < pow(2, N - 1)) {
			if (c >= 0 && c < pow(2, N - 1)) factor = 0;
			else {
				c -= pow(2, N - 1);
				factor = 1;
			}
		}
		else {
			r -= pow(2, N - 1);
			if (c >= 0 && c < pow(2, N - 1)) factor = 2;
			else {
				c -= pow(2, N - 1);
				factor = 3;
			}
		}

		ans += (pow(2, N) * pow(2, N) / 4  * factor);

		N--;

		if (N == 0) break;
	}

	cout << ans << "\n";

}