//1992 - 쿼드 트리
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int N;          // N = 2 ^ k, 0 <= k <= 6
char**arr;      // N * N

/**
 * arr : 원본 2차원 배열
 * N : log (한 변의 길이)
 * x : 시작 행 인덱스 (왼쪽 위 인덱스)
 * y : 시작 열 인덱스 
*/
vector<char> zip(int N, int x, int y) {

    vector<char> ans;   //반환할 부분벡터

    //최소 조건
    if(N == 1) {
        ans.push_back(arr[x][y]);
        return ans;
    }
    
    //4분할
    vector<char> lu = zip(N/2, x, y);
    vector<char> ru = zip(N/2, x, y + N/2 );
    vector<char> ld = zip(N/2, x + N/2, y);
    vector<char> rd = zip(N/2, x + N/2, y + N/2);

    //모두 0 또는 1로 같은 경우 - 압축 가능
    vector<char> z = {'0'};
    vector<char> o = {'1'};
    if(lu == ru && ru == ld && ld == rd) {
        if(rd == z) return z;
        else if(rd == o) return o;
    } 

    //다른 경우 병합( 괄호 사용 )
    ans.push_back('(');
    ans.insert(ans.end(), lu.begin(), lu.end());
    ans.insert(ans.end(), ru.begin(), ru.end());
    ans.insert(ans.end(), ld.begin(), ld.end());
    ans.insert(ans.end(), rd.begin(), rd.end());
    ans.push_back(')');

    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //input
    cin >> N;
    cin.ignore();
    arr = new char*[N];
    for(int i=0;i<N;i++) {
        char* ch = new char[N + 1];
        cin.getline(ch, N + 1);
        arr[i] = ch;
    }
    
    //solve
    vector<char> res = zip(N, 0, 0);
    for(auto c : res) cout << c;

}