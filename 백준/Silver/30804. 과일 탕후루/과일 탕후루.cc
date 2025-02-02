#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> fruits;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        fruits.push_back(tmp);
    }
    
    //two-pointer 
    int l = 0, r = 0, num_of_types = 1, max_len = 1; 
    int num_of_each_fruits[10] = {0, };
    
    //init
    num_of_each_fruits[fruits[l]]++;
    
    while(r < N) {
        // 2종류 초과면 l++로 길이 감소 
        // 2종류 이하면 r++로 길이 증가
        
        // r++일 때(길이가 증가할 때)마다 과일 종류 수와 최대 길이 업데이트
        
        if(num_of_types > 2) {
            num_of_each_fruits[fruits[l]]--;
            if(num_of_each_fruits[fruits[l]] == 0) num_of_types--;
            l++;
        }
        
        else {
            if(num_of_types <= 2) max_len = max(max_len, r - l + 1);
            r++;
            if(num_of_each_fruits[fruits[r]] == 0) num_of_types++;
            num_of_each_fruits[fruits[r]]++;
        }
    }
    
    cout << max_len;
    
    return 0;
}
