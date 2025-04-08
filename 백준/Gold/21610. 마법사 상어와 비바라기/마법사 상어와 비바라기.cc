/*
주의할 점)
문제에선 구름이 사라지고 물복사버그를 쓴다고 되어있지만
'2에서 물이 증가한 칸'에 대해서만 마법을 쓰고, 이는 구름이 있던 자리이므로
마법을 쓰고 나서 구름 행렬을 초기화해야 함!

그리고 5번에서 구름을 새로 만들 때도 '구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다'는 조건이 있으므로 
구름이 있던 자리 정보를 마찬가지로 알아야 함!

1 -> 2 -> 4 -> 3과5(동시) 순으로 실행해야 함!

*/

#include <iostream>

using namespace std;

int N, M;
bool clouds[50][50];
int buckets[50][50];
int moves[100][2];
int dx[8] = { 0, -1, -1, -1, 0, 1, 1,  1};
int dy[8] = {-1, -1,  0,  1, 1, 1, 0, -1};

//debugging functions
void displayClouds() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << clouds[i][j] ? 1 : 0 << ' ';
            cout << '\n';
    }
}

//debugging
void displayBuckets() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << buckets[i][j] << ' ';
        cout << '\n';
    }
}
        


// 1번 항목 시뮬레이션 함수
void moveClouds(int d, int s) {
    
    bool newClouds[50][50] = {false, };
    
    //이동
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            
            //이동 후 좌표 계산
            if(clouds[i][j]) {
                int nx = (((i + dx[d - 1] * s) % N) + N) % N; // 음/양 모든 경우에 사용 가능한 좌표 계산식!
                int ny = (((j + dy[d - 1] * s) % N) + N) % N;
                
                newClouds[nx][ny] = true;
            }
            
        }
    }    
    
    //복사
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            clouds[i][j] = newClouds[i][j];
        }
    } 
    return ;
}



int main() {
    
    //input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j =0; j < N; j++) {
            cin >> buckets[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> moves[i][0] >> moves[i][1];
    }
    
    //비바라기로 초기 구름 생성
    clouds[N-1][0] = true;
    clouds[N-1][1] = true;
    clouds[N-2][0] = true;
    clouds[N-2][1] = true;
    
    //시뮬레이션 시작
    for(int m = 0; m < M; m++) {
        
        //1. 구름 이동
        moveClouds(moves[m][0], moves[m][1]);
        
        //debugging
        //cout << "===" << m << "번째 이동 후 구름 위치===" << '\n';
        //displayClouds();
        
        //2. 구름에서 비 내리기
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(clouds[i][j]) {
                    buckets[i][j]++;
                }
            }
        }
        
        //debugging
        //cout << "===" << m << "번째 비 내리기===" << '\n';
        //displayBuckets();
        
        //4. 물이 증가한 칸에 복사버그마법 시전
        //모든 곳에 비가 다 내리고 나야 제대로 계산 가능하므로 
        // 2번과 별도의 for문으로 돌려야 함!
        
        int add_amount[50][50] = {0, }; //마법으로 인한 물 증가량 행렬
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                
                //물이 증가한 칸에만 복사버그마법 시전
                if(clouds[i][j]) {

                    //대각선이므로 2, 4, 6, 8번 방향만 확인
                    for(int k = 1; k < 8; k += 2) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        //유효한 칸인 경우 바구니 당 1씩 증가
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N && buckets[nx][ny] > 0) add_amount[i][j] += 1;
                    }
                }
            }
        }
        
        // 실제로 증가한 양을 더하는 것도 증가량을 다 구하고 나서 별도의 for문으로 돌려야 함
        // 물이 0인 곳이 더해서 1이상이 되버리면 다른 칸 복사마법 계산에 영향을 주기 때문
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                
                buckets[i][j] += add_amount[i][j];
            }
        }
        //debugging
        //cout << "===" << m << "번째 복사마법===" << '\n';
        //displayBuckets();
        
        //3 & 5 기존 구름 제거 및 새 구름 생성
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                
                if(!clouds[i][j] && buckets[i][j] >= 2) {
                    clouds[i][j] = true;
                    buckets[i][j] -= 2;
                }
                else if(clouds[i][j]) clouds[i][j] = false;
            }
        } 
        
        //debugging
        //cout << "===" << m << "번째 새 구름===" << '\n';
        //displayClouds();
        
        
        //debugging
        //cout << "===" << m << "번째 단계 완료===" << '\n';
        //displayBuckets();
    }
    
    // M번의 이동이 모두 끝난 후 점수 계산
    int total_score = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            total_score += buckets[i][j];
        }
    }
    cout << total_score << '\n';
    return 0;
}