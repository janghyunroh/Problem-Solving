//7576 - 토마토
//1인 모든 지점에 대해 동시에 bfs -> 1인 좌표를 모두 큐에 삽입
//큐에서 빼면서 상하좌우 중 0인 지점에 대해 일차수로 바꾸고 큐에 넣기
//총 일수는 arr의 해당 좌표에 현재 일차수를 저장함으로써 구하기 

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N;
int**arr;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<int, int>> q; //좌표(행 / 열)
    //q.first : 
    //q.second:


    //1인 좌표를 모두 q에 삽입 -> O(MN)
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    //visited 표시는 값을 1로 바꿈으로써 구현
    //bfs시작
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        //방문 좌표 및 방문 일차수 추출
        int curRow = cur.first;
        int curCol = cur.second;

        //해당 좌표의 인접 좌표에 대한 방문 실행
        //인접 좌표
        //1. 범위 내에 있어야 함
        //2. 상하좌우여야 함
        //3. 값이 0이어야 함
        for(int i=0;i<4;i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];
            int nextDay = arr[curRow][curCol] + 1;

            if(nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M && arr[nextRow][nextCol] == 0) {
                arr[nextRow][nextCol] = nextDay;
                q.push(make_pair(nextRow, nextCol));
            }
        }
    }

    //bfs 종료, 다시 한 번 arr 돌면서 0 있는지 확인 & 최대 일수 구하기 O(MN)
    int ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 0) {
                cout << -1;
                return;
            }
            else if(ans != -1)
                ans = max(ans, arr[i][j]);
            else continue;
        }
    }
    cout << ans - 1;
    return;

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    arr = new int*[N + 1];
    for(int i=0;i<N;i++) {
        arr[i] = new int[M + 1];
        for(int j = 0; j<M;j++) {
            cin >> arr[i][j];   //i가 행 번호(세로), j가 열 번호(가로)
        }
    }
    bfs();
    return 0;
}