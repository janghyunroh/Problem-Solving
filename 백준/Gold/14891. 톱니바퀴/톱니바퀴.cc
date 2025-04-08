/*
회전하는 물체 + 물체의 특정 부분(중간 요소)에 접근
--> 덱 회전 사용!

12시 톱니부터 시계방향으로 주어짐.
-> front가 12시, 오른쪽과 비교시 idx=2, 왼쪽과 비교시 idx=6

회전방향: 1=시계, 0=정지, -1=반시계

모든 톱니의 회전방향을 양쪽에 전파하며 다 구한 다음
다 구하고 나면 각 톱니를 회전. 
*/

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int K;
deque<int> *dqs = new deque<int>[4];

// 방향이 결정된 톱니를 실제로 돌리는 함수
void rotate_single_wheel(int wheel_num, int direction) {
    if(direction == 0) return;
    else if(direction == 1) { // 시계방향 회전 -> back을 pop해서 front에 push
        int tmp = dqs[wheel_num].back(); dqs[wheel_num].pop_back();
        dqs[wheel_num].push_front(tmp);
        
    }
    else if(direction == -1) { // 반시계방향 회전 -> front를 pop해서 back에 push
        int tmp = dqs[wheel_num].front(); dqs[wheel_num].pop_front();
        dqs[wheel_num].push_back(tmp);
    }
    return ;
}

// 방향이 결정된 바퀴 옆 바퀴의 방향을 구하는 함수
int evaluateRotationDirection(int root_wheel, int cur_wheel, int direction) {
    if(direction == 0) return 0;
    if(root_wheel < cur_wheel) { // 돌아가는 바퀴의 오른쪽에 있는 경우 - 2와 6을 비교
        if(dqs[root_wheel][2] != dqs[cur_wheel][6]) { // 다른 극인 경우
            return -direction;
        }
        else return 0;
    }
    else if(root_wheel > cur_wheel) { // 돌아가는 바퀴의 왼쪽에 있는 경우 - 6과 2를 비교
        if(dqs[root_wheel][6] != dqs[cur_wheel][2]) { // 다른 극인 경우
            return -direction;
        }
        else return 0;
    }
    return 0;
}

//wheel번째 바퀴를 돌렸을 때 모든 톱니의 움직임을 시뮬레이션하는 함수
void simulate(int wheel, int direction) {
    int moves[4];
    moves[wheel] = direction;
    
    //방향 구하기
    for(int i = wheel - 1; i >= 0; i--) { //왼쪽으로 전파
        moves[i] = evaluateRotationDirection(i + 1, i, moves[i + 1]);
    }
    for(int i = wheel + 1; i < 4; i++) { // 오른쪽으로 전파
        moves[i] = evaluateRotationDirection(i - 1, i, moves[i - 1]);
    }
    
    //모든 톱니 회전
    for(int i = 0; i < 4; i++) {
        rotate_single_wheel(i, moves[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //input - 붙어있는 채로 들어오므로 getline 사
    for(int i = 0; i < 4; i++) {
        
        string s;
        getline(cin, s);
        
        for(int j = 0; j < 8; j++) {
            int tmp = (int)(s[j] - '0');
            dqs[i].push_back(tmp);
        }
    }
    
    cin >> K;
    int wheel, direction;
    for(int i = 0; i < K; i++) {
        cin >> wheel >> direction;
        simulate(wheel - 1, direction); // 인덱스이므로 -1
    }
    
    // 점수 계산
    int score = 0;
    for(int i = 0; i < 4; i++) {
        score += dqs[i][0] * pow(2, i);
    }
    
    cout << score << '\n';
    
    return 0;
}
