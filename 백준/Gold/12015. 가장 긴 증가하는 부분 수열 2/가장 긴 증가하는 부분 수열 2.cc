//12015

#include <iostream>
#include <vector>

using namespace std;

int N;
int* arr;

int solve() {
    
    vector<int> ans;
    for(int i=0;i<N;i++) {
        //각 원소에 대한 이분탐색 실시
        int l = -1, r = ans.size();
        while(l + 1 < r) {
            int mid = (l + r) / 2;
            if(ans[mid] < arr[i]) l = mid;
            else r = mid;
        }
        if(r==ans.size()) ans.push_back(arr[i]);
        else ans[r] = arr[i];
    }
    return ans.size();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    arr = new int[N];
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    cout << solve() << "\n";
    return 0;
}