//Chuck Norris

/*
time 1초, space 128MB -> DP 불가능
long K 에 대응되는 N을 찾기 -> 이진 탐색

check(   )의 형태는?

ex) K = 11

1220324526072892100112 . . .
1 2 3 45 6 7 89 10 11 . . .
1                  K         10^15
        ^          
        N          

1 <= N <= K

1 ~ 11 binarySearch

mid = (1 + K) / 2 = 6
6 -> 60

( 이전의 숫자 총 개수 + 1 ) <=          K             <= ( 이전의 숫자 총 개수 + 이번 A의 길이 )

122032452 (9개) + 60(1개 ~ 2개) -> 10 ~ 11 <- k=11이 범위 내 존재 
-> N = mid(6)

60

K - 이전 문자 개수 = 11 - 10 = 1
-> 60의 1번쨰 문자 6


* 범위 밖인 경우
if K < ( 이전의 숫자 총 개수 + 1 ) hi = mid - 1
if K > ( 이전의 숫자 총 개수 + 이번 A의 길이 ) lo = mid + 1


*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


//숫자 n의 길이 반환
long length(long n) {
    return to_string(n).size();
}


/*
N 이전까지의 모든 A[N]의 자리수 개수를 세는 방법

더 적은 자리수의 숫자들의 자리수 합 + 같은 자리수의 숫자들의 자리수 합
ex) 4397 -> 4자리수
1, 2, 3자리수 all + 4자리수 개수(1000~4387)


1 * 9 +        <- 한 자리수 개수(9 - 0)
2 * 90 +        <- 두 자리수 개수(99 - 9)
3 * 900 +       <- 세 자리수 개수(999 - 99)
. . .           
l * ()          <- l 자리수 개수 ( = (1~N개수) - (l-1 자리수 개수) )
                              ( = N - ( 10^(l-1) - 1 ) )
                              ( = N - pow(10, l - 1) + 1)

Full인 부분을 구하는 함수 + len * ( N - pow(10, l - 1) + 1 ) 형태로 계산
*/

//Full 부분 구하는 함수
long getFull(long l) {
    long ans = 0;
    for(int i=0;i<l-1;i++) {
        ans += (i + 1) * 9 * pow(10, i);
    }
    return ans;
}

//N 이전까지의 모든 A[N]의 자리수 개수를 세는 함수
long f(long n) {
    long len = length(n);
    long base = (long) pow(10, len - 1);
    return getFull(len) + len * (n - base + 1);
}

//A[N] 이전 숫자의 총 개수 구하는 함수
long beforeNum(long N) {
    if(N==1) return 0;
    long m = (N - 1) / 4;   // N 이전에 오는 숫자들 중 4의 배수의 개수
    return f(N - 1) + (N - 1 - m);

}

//풀이 함수(주어진 K에 대한 S(K) 반환 함수
int solve(long K) {

    //이진 탐색
    long lo = 1;
    long hi = 1000000000000000L;    // 10 ^ 15

    while(true) {
        long mid = (lo + hi) / 2;       

        long h = beforeNum(mid);
        long l = length(mid);

        long idx1 = h;  //mid의 앞에 오는 모든 숫자들의 개수 = mid의 첫 글자의 인덱스 
        long idx2 = h + (mid % 4 == 0 ? l - 1 : l);     //mid의 마지막 글자의 인덱스 = h + len - 1 (4의 배수가 아니면 한 글자 더 붙음)


        //checking
        if(idx1 <= K && K <= idx2) {    // 이진 탐색 - found
            if(K == idx2 && mid % 4 != 0) {//K가 대응되는 N의 마지막 인덱스이고 N이 4의 배수인 경우 - 0 or 2
                return (mid % 2 == 0) ? 0 : 2;  //10의 자리가 짝수면 0, 홀수면 2      ex) 20 / 32
            }
            return (int)(to_string(mid).at((int)(K - idx1)) - '0');
        }

        //이진 탐색 - 
        else if(idx2 < K) lo = mid + 1;

        //이진 탐색 - 
        else if(K < idx1) hi = mid - 1; 

        else break;
    }

    return -1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //input
    while(1) {
        long K;
        cin >> K;
        if(K==0) break;

        cout << solve(K - 1) << "\n";
    }

}
