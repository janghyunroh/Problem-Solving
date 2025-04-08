#include <iostream>

using namespace std;

int N, K, L;

// 게임 보드를 나타내는 행렬
// int, int pair로 이루어졌으며 첫 값은 셀의 종류, 둘째값은 뱀의 일부분인 경우 방향.
// 0: 빈 칸
// 1: 뱀
// 2: 사과
//방향의 경우 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위.
//초기엔 모두 0, 0으로 초기화
//시작점만 1, 0
pair<int, int> board[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int hx = 0, hy = 0; // 머리의 위치
int tx = 0, ty = 0; //꼬리의 위치 - 초기엔 머리와 꼬리가 동일.

//방향 전환 배열
char command[10000];

//debugging
void displayBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j].first << ' ';
        }
        cout << '\n';
    }
}

bool simulate(char direction_change) {
    
    
    
    // 0. 방향 변경 반영 
    if(direction_change == 'L') { // 반시계 방향(--)
        
        board[hx][hy].second = (board[hx][hy].second  + 3) % 4;
    }
    else if(direction_change == 'D') { // 시계 방향(++)
        board[hx][hy].second = (board[hx][hy].second + 1) % 4;
    }
    
    // 1. 몸길이를 늘려 머리를 다음 칸에 위치. 
    int hd = board[hx][hy].second;
    int nx = hx + dx[hd]; int ny = hy + dy[hd];
    
    // 2. 벽이나 몸에 부딪히는 경우 게임 종료
    if(nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny].first == 1) {
        return false;
    }
    
    // 3. 이동한 칸에 사과가 있는 경우
    if(board[nx][ny].first == 2) {
        
        // 
        board[nx][ny].first = 1;
        board[nx][ny].second = hd;
        
        //머리 이동 반영
        hx = nx; hy = ny;
        
    }
    
    // 4. 이동한 칸에 사과가 없는 경우
    else {
        int td = board[tx][ty].second;
        int ntx = tx + dx[td];
        int nty = ty + dy[td];
        
        //머리 칸 갱신
        board[nx][ny].first = 1;
        board[nx][ny].second = hd;
        
        //머리 이동 반영
        hx = nx; hy = ny;
        
        //꼬리 칸 날리기
        board[tx][ty].first = 0;
        board[tx][ty].second = 0;
        
        //꼬리 이동 반영 
        tx = ntx; ty = nty;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //init
    for(int i = 0; i < 10000; i++) command[i] = '0';
    
    cin >> N;
    cin >> K;
    for(int i = 0; i < K; i++) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        board[tmp1 - 1][tmp2 - 1].first = 2;
    }
    cin >> L;

    for(int i = 0; i < L; i++) {
        int idx; char cmd;
        cin >> idx >> cmd;
        command[idx] = cmd;
    }
    
    
    int cnt = 0;
    while(simulate(command[cnt])) {
        cnt++;
        
        //debugging
        //cout << "==="<< cnt << "초 이후의 보드 상태" << "===\n"; 
        //displayBoard();
        
    }
    cout << cnt + 1;
    return 0;
}