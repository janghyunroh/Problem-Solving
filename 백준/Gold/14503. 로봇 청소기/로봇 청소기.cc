#include <iostream>

using namespace std;

int N, M, r, c, d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int room[50][50];

int simulate() {
    int cnt = 0;
    while(true) {
        
        //1. 현재 칸이 청소되지 않은 경우 청소하기
        if(room[r][c] == 0) {
            room[r][c] = -1;
            cnt++;
        }
        
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
        bool found = false;
        for(int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(room[nx][ny] == 0) { 
                found = true;
            }
        }
        
        if(found) { // 3. 청소되지 않은 빈 칸이 있는 경우
            d = (d + 3) % 4; //반시계로 90도 회전
            int mx = r + dx[d];
            int my = c + dy[d];
            if(room[mx][my] == 0) {// 바라보는 곳이 청소가 안된 빈칸인 경우
                r = mx; c = my; // 한 칸 전지 
            }
        }
        
        // 2. 청소되지 않은 빈 칸이 없는 경우
        if(!found) {
            //후진 가능한지 확인
            int back_dir = (d + 2) % 4;
            int nx = r + dx[back_dir];
            int ny = c + dy[back_dir];
            if(room[nx][ny] == 1) { // 2-b. 후진이 불가한 경우
                return cnt; // 작동 멈추기
            }
            
            // 2-a. 후진이 가능한 경우 후진 후 1번으로 돌아가기
            r = nx; c = ny;
        } 
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }
    int cnt = simulate();
    cout << cnt << '\n';
    return 0;

}