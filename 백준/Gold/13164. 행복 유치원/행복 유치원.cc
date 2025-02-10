//13164

#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int *dif;
int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    arr = new int[N];
    dif = new int[N - 1];
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        if(i>0) {
            dif[i - 1] = arr[i] - arr[i - 1];
        }
    }

    sort(dif, dif + N - 1);
    int sum = 0;
    for(int i=0;i<N - K; i++) sum += dif[i];
    cout << sum << "\n";

    return 0;
}