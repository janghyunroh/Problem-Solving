#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H; 
int***box;
bool***visit;

int dh[6] = {0, 0, 0, 0, 1, -1};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dm[6] = {1, -1, 0, 0, 0, 0};

//3차원 배열에 대한 너비 우선 탐색 - O(N^3)
int travel() {
    int days = 0;
    bool full = true;
    //배열에서 1을 찾아 큐에 넣기 - O(N^3)
    queue<tuple<int, int, int, int>> q;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(box[i][j][k] == 1) {
                    visit[i][j][k] = true;
                    q.push(make_tuple(i, j, k, 0));
                }
                else if( box[i][j][k] == 0) full = false;
            }
        }
    }
    if(full) return 0;

    //큐가 빌 때까지 traversal - 최대 O(N^3)
    while(q.size()) {

        //pop
        int h, n, m, curDay;
        tie(h, n, m, curDay) = q.front();
        q.pop();

        //
        box[h][n][m] = 1;
        days = max(days, curDay);
        //
        for(int i=0;i<6;i++) {
            int nh = h + dh[i];
            int nn = n + dn[i];
            int nm = m + dm[i];

            if(nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < M) {//범위 내이고
                if(box[nh][nn][nm] == 0 && !visit[nh][nn][nm]) {//토마토가 들어있고, 방문하지 않았다면
                    visit[nh][nn][nm] = true; //방문 처리
                    q.push(make_tuple(nh, nn, nm, curDay + 1)); //방문 예정 큐에 넣기
                }
            }
        }
    }
    
    return days;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;

    //box[H][N][M] 배열 동적 할당 및 값 입력 - O(N^3)
    box = new int**[H];
    visit = new bool**[H];
    for(int i = 0; i < H; i++) {
        box[i] = new int*[N];
        visit[i] = new bool*[N];
        for(int j = 0; j < N; j++) {
            box[i][j] = new int[M];
            visit[i][j] = new bool[M];
            for(int k = 0; k < M; k++) {
                int a; cin >> a;
                box[i][j][k] = a;
                visit[i][j][k] = false;
            }
        }
    }

    int days = travel(); //O(N^3)

    //debugging
    // for(int i = 0; i < H; i++) {
    //     for(int j = 0; j < N; j++) {
    //         for(int k = 0; k < M; k++) {
    //             cout << box[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    //방문 못한 토마토가 있는지 확인 - O(N^3)
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << days;
    return 0;
}