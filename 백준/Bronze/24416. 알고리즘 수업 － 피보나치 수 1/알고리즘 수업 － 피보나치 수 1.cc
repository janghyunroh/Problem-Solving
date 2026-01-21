#include <iostream>
#include <vector>

using namespace std;

int N;

int fib(int n) {
    vector<int> arr(N, 0);
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[N-1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cout << fib(N) << ' ' << N - 2;
    return 0;
}
