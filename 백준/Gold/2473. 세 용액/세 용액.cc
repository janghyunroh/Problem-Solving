//2473 - 세 용액
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
ll * arr;

//-1,000,000,000 이상  1,000,000,000 이하
//sum의 최댓값은         3,000,000,000 

void solve() {

    ll sum = 3000000001;
    int k, le, ri;  //  정답 포인터

    for(int i = 0; i < N; i++) {
        int l = i + 1;
        int r = N - 1;


        while(l < r) {
            ll tmp = arr[i] + arr[l] + arr[r];
            if(abs(tmp) < sum) {
                sum = abs(tmp);
                k = i; 
                le = l; 
                ri = r;
            }
            if(tmp > 0) r--;
            else if(tmp < 0) l++;
            else {  //0을 찾은 경우 - 즉각 출력
                cout << arr[i] << " " << arr[l] << " " << arr[r];
                return;
            }
        }
    }

    cout << arr[k] << " " << arr[le] << " " << arr[ri];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    arr = new ll[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    solve();

    return 0;
}