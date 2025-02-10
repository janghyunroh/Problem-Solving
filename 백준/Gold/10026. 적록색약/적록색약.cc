//적록색약

#include <iostream>
#include <vector>

using namespace std;

int N;
char **arr;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool **visit;

void DFS(int x, int y, char color) {
    visit[x][y] = true;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N) {
            if(arr[nx][ny] == color && !visit[nx][ny]) {
                DFS(nx,ny,color);
            }
        }
    }
}

void DFS_RG(int x, int y, char color) {
    visit[x][y] = true;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N) {
            if(!visit[nx][ny]) {
                if(color == 'R' || color == 'G') {
                    if(arr[nx][ny] == 'R' || arr[nx][ny] == 'G') {
                        DFS_RG(nx,ny,color);
                    }
                } else {
                    if(arr[nx][ny] == color) {
                        DFS_RG(nx,ny,color);
                    }
                }
            }
        }
    }
}

int countArea() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j =0;j<N;j++) {
            if(!visit[i][j]) {
                DFS(i,j,arr[i][j]);
                cnt++;
            }
        }
    }


    for(int i=0;i<N;i++) {
        for(int j =0;j<N;j++) {
            visit[i][j] = false;
        }
    }
    
    return cnt;
}

int countArea_RG() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j =0;j<N;j++) {
            if(!visit[i][j]) {
                DFS_RG(i,j,arr[i][j]);
                cnt++;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j =0;j<N;j++) {
            visit[i][j] = false;
        }
    }

    return cnt;
}

int main() {
    cin >> N;
    arr = new char*[N];
    visit = new bool*[N];
    for(int i=0;i<N;i++) {
        arr[i] = new char[N];
        visit[i] = new bool[N];
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            visit[i][j] = false;
        }
    }

    cout << countArea() << " " << countArea_RG() << endl;
}