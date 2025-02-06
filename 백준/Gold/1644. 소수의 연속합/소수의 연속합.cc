//1644 - 소수의 연속합

#include <iostream>
#include <vector>

using namespace std;

int N;

int solve(int N) {

    int cnt = 0;    //경우의 수(반환값)
    vector<int>primes;  //N이하의 소수들을 오름차순으로 저장해둔 벡터

    //에라토스테네스의 체
    bool* arr = new bool[N + 1];
    arr[1] = false;
    for(int i=2;i<=N;i++) arr[i] = true;    //O(N)

    for(int i = 2; i * i <= N; i++) {      //O(N^1/2)
        if(arr[i]) 
            for(int j = i * i; j <= N; j += i) //O(N)
                arr[j] = false;
    }

    //완성된 배열로 벡터에 원소 삽입
    for(int i=1;i<=N;i++) { //O(N)
        if(arr[i]) primes.push_back(i);
    }

    if(primes.empty()) return 0;

    //벡터는 이미 정렬된 상태임.
    //완성된 소수 집합 벡터로 투 포인터 돌리기
    int l = 0, r = 0;
    int sum = primes[0];
    int n = primes.size();
    while(true) {
        if(sum < N) {
            if(r + 1 > n) break;
            r++;
            sum += primes[r];
        }
        else if(sum > N) {
            sum -= primes[l];
            l++;
        }
        else {  //found
            cnt++;
            sum-= primes[l];
            l++;
        }
    }
    return cnt;
}

int main() {
    cin >> N;
    cout << solve(N);
}