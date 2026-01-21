#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 벡터를 전역 혹은 참조로 전달하여 복사 비용 제거
ll solve(vector<ll> &v, int start, int end) {
    // 기저 사례: 구간 크기가 0
    if(start == end) return 0;
    // 기저 사례: 구간 크기가 1
    if(start + 1 == end) return v[start];

    int mid = (start + end) / 2;

    // 1. 왼쪽, 오른쪽 분할 정복
    ll res = max(solve(v, start, mid), solve(v, mid, end));

    // 2. 중간(mid)을 걸쳐있는 직사각형 처리
    // lo: mid-1 (왼쪽), hi: mid (오른쪽) 에서 시작
    int lo = mid - 1;
    int hi = mid;
    
    ll height = min(v[lo], v[hi]);
    ll width = 2;
    res = max(res, height * width);

    // 양쪽 구간 끝에 닿을 때까지 확장
    // start <= lo 그리고 hi < end 인 상황 유지
    while(lo > start || hi < end - 1) {
        
        // 오른쪽으로 갈 수 있고, (왼쪽이 막혔거나 OR 오른쪽 다음 높이가 더 크면) -> 오른쪽 이동
        // hi < end - 1 체크가 반드시 먼저 와야 함 (인덱스 오류 방지)
        if(hi < end - 1 && (lo == start || v[lo-1] < v[hi+1])) {
            hi++;
            height = min(height, v[hi]);
        }
        else { // 왼쪽 이동
            lo--;
            height = min(height, v[lo]);
        }
        
        width++;
        res = max(res, width * height);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        int N; 
        cin >> N;
        if(N == 0) break;
        
        vector<ll> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
        
        // [0, N) 범위 (반열린 구간)
        cout << solve(v, 0, N) << '\n';
    }
    return 0;
}