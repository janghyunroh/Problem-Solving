#include <iostream>
#define INF 500000
using namespace std;

int N, M;
bool broken[10];

//O(log n)
int digits(int n) {
	if (n == 0) return 1;

	int digit = 0;
	while (n > 0) {
		n /= 10;
		digit++;
	}
	return digit;
}

bool possible(int n) {
	if(n==0)
		return !broken[0];
	while (n > 0) {
		int d = n % 10;
		if(broken[d]) 
			return false; 
		n /= 10;
	}
	return true;
}

int main() {
	cin >> N;
	cin >> M;
	if (M) {
		for (int i = 0; i < M; i++) {
			int a;  cin >> a;
			broken[a] = true;
		}
	}

	int min_ = INF;

	for (int i = 0; i <= 999999; i++) {
		int cnt = 0;
		if (i == 100) {	// + / - 만 입력
			cnt += (N - i > 0 ? N - i : i - N);
		}
		else {	//채널 변경 후 + / - 입력
			if (!possible(i)) continue;
			cnt += digits(i);
			cnt += (N - i > 0 ? N - i : i - N);
		}
		min_ = min(min_, cnt);
	}
	cout << min_;
	return 0;
}