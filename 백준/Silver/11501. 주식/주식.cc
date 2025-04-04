#include <iostream>

typedef long long ll;

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T, N;
    int* arr;
    
    cin >> T; 
    while(T--) {
        cin >> N;
        arr = new int[N];
        for(int i =0; i < N; i++) {
            cin >> arr[i];
        }
        
        int mx = 0;
        ll score = 0;
        
        for(int i = N - 1; i >= 0; i--) {
            if(mx > arr[i]) {
                score += (mx - arr[i]);
            }
            else {
                mx = arr[i];
            }
        }
        cout << score << '\n';
    }
}
