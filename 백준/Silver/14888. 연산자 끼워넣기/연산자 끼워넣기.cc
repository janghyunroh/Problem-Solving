#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> opers;
int nums[11];
int mx = -1000000001, mn = 1000000001;
int numsOfOpers[4] = {0, };

void calculateAndCompare() {
    int val = nums[0];
    for(int i = 0; i < N - 1; i++) {
        if(opers[i] == 0) val += nums[i + 1];
        else if(opers[i] == 1) val -= nums[i + 1];
        else if(opers[i] == 2) val *= nums[i + 1];
        else val /= nums[i + 1];
    }
    
    //compare
    mx = max(mx, val);
    mn = min(mn, val);
}

void solve(int step) {
    
    //term case
    if(step == N - 1) {
        calculateAndCompare();
        return ;
    }
    
    // avg case
    for(int i = 0; i < 4; i++) {
        if(numsOfOpers[i] > 0) {
            numsOfOpers[i] --;
            opers.push_back(i);
            solve(step + 1);
            opers.pop_back();
            numsOfOpers[i]++;
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> numsOfOpers[i];
    }
    solve(0);
    cout << mx << '\n' << mn << '\n';
    return 0;
}