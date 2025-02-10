
/**
 * 양방향 회전 -> 덱 사용
 * 90도씩 회전 -> 덱의 상태 나타내는 변수? 덱? 사용
 * 처음에 왼쪽이 큐의 뒤, 오른쪽이 큐의 앞임! <- 주의) push시 push_front 할 것
 * push -> 무조건 push_front
 * pop -> 무조건 pop_back
 *
 * 중력에 의한 떨어짐 -> 상태에 따라 push_front / push_back
 * //떨어지는 함수 별도 생성
 *
 * 1 : f = b
 *
 *     f
 * 2 :| |
 *     b
 *
 * 3 : b = f
 *
 *     b
 * 4: | |
 *     f
 *
 * 1 -> 4로 갈수록 rotate r
 * 4 -> 1로 갈수록 rotate l
 * 1 <-> 4 일 때 있음(원순열) -> 상태 덱 사용
 * state = {1, 2, 3, 4}
 * 순수 pop 없이 회전용으로만 사용
 *
 * 1)push
 * push 시에 상태 판별 & front/back이 w가 아니면 바로 pop
 * 1 or 3 state -> 문제 없음
 * 2 -> back쪽을 w가 나올때까지 pop
 * 4 -> front 쪽을 w가 나올때까지 pop
 *
 * 2) pop
 * b일 땐 아무 문제 없음(b라는 건 1 / 3 상태라는 뜻)
 * w인 경우
 * 1 , 3 상태 -> 문제 없음
 * 2 상태 -> back쪽을 w가 나올떄까지 pop
 * 4 상태 -> front쪽을 w가 나올때까지 pop
 *
 * 3) rotate
 * rotate r : clockwise ( 1 -> 4 )
 * {1, 2, 3, 4}
 * {2, 3, 4, 1}
 *
 * int n = state.front()
 * state.pop_front()
 * state.push_back(n)
 *
 * rotate l
 *
 * int n = state.back()
 * state.pop_back()
 * state.push_front(n)
 *
 * 회전 후 상태 판별하여 pop 수행
 *  while(gdq.front()/back() != 'b') gdq.pop()
 *
*/

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

//떨어뜨리는 함수
//매 push, rotate, pop 마다 실행
void drop(deque<char>& gdq, deque<int>& state, int &num_b) {
    if (state.front() == 1 || state.front() == 3) return;
    else if (state.front() == 2) {
        //  f
        // | |
        //  b
        while ( !gdq.empty() && gdq.back() != 'w') {
            gdq.pop_back();
            num_b--;
        }
        return;
    }

    else if (state.front() == 4) {
        //  b
        // | |
        //  f
        while ( !gdq.empty() && gdq.front() != 'w') {
            gdq.pop_front();
            num_b--;
        }
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char c, cmd[7];
    cin >> N;

    //count를 위한 개수 변수
    int num_b = 0;
    // 가림막 개수는 gdq.size() - num_b

    deque<char> gdq; //gravity deque
    deque<int> state;//상태 덱
    for (int i = 1; i <= 4; i++) state.push_back(i);   //덱의 front가 상태값
    //state = {1, 2, 3, 4}
    //         ^
    //      현재 이 상태 ( f ==== b)

    while (N--) {
        cin >> cmd;

        //1) push
        if (!strcmp(cmd, "push")) {
            cin >> c;
            if (c == 'b') ++num_b;
            gdq.push_front(c);
            drop(gdq, state, num_b);
        }
        else if (!strcmp(cmd, "pop")) {
            if (gdq.empty()) continue;
            else if (gdq.back() == 'b') --num_b;
            gdq.pop_back();
            drop(gdq, state, num_b);
        }
        else if (!strcmp(cmd, "rotate")) {
            cin >> c;
            if (c == 'r') {
                int n = state.front();
                state.pop_front();
                state.push_back(n);

                drop(gdq, state, num_b);
            }
            else if (c == 'l') {
                int n = state.back();
                state.pop_back();
                state.push_front(n);

                drop(gdq, state, num_b);
            }
        }
        else if (!strcmp(cmd, "count")) {
            cin >> c;
            if (c == 'b') cout << num_b << "\n";
            else if (c == 'w') cout << gdq.size() - num_b << "\n";
        }
    }

    return 0;
}
