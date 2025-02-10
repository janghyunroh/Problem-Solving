//2470 - 두 용액
#include <iostream>
#include <algorithm>

using namespace std;
//using ll = long long;

int N;
int *arr;

void solve() {
    int sum = 2000000001;
    int le, ri;

    int l = 0;
    int r = N - 1;
    while(l < r) {
        int tmp = arr[l] + arr[r];
        if(abs(tmp) < sum) {
            sum = abs(tmp);
            le = l;
            ri = r;
        }
        if(tmp > 0) r--;
        else if(tmp < 0) l++;
        else {
            cout << arr[l] << " " << arr[r];
            return;
        }
    }

    cout << arr[le] << " " << arr[ri];
    return;
}

int main() {
    cin >> N;
    arr = new int[N];
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    solve();
}