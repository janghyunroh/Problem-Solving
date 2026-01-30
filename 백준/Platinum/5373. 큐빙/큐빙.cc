//Boj 5373 - 큐빙

//주의 사항 1: 가운데 줄이 회전하는 경우는 문제 상황에 존재하지 않음! -> 무조건 한 면과 그에 대응되는 4개의 1x3 변이 회전!
// => 
//주의 사항 2: 시계/반시계는 그 면을 바라봤을 때 기준임!!!!
// 어느 면이 바닥에 오게 두는지는 상관 없지만(어차피 다 돌아가므로), 어느 면을 바라보고 있는지는 중요!

// 배열 기준을 어떻게 잡아야 편하게 구현이 가능한가?
// 바닥에 아랫면이 오도록 두었을 때를 가정하고 
// 각 면을 정면으로 오게 바라봤을 때 기준으로 두면?
// 아랫면은 아래에서 위를 바라보게? 위에서 아랫면을 투과해서 보게?
// 윗면 회전 -> 4개 옆면들 모두 상단이 이동
// 아랫면 회전 -> 4개 옆면들 모두 하단이 이동

// 나머지 옆면의 회전은 어떻게 해도 각 면의 이동하는 변이 서로 다름 (구현 난이도는 똑같을 듯?)

// 2차원 배열 6개 -> 6 x 3 x 3 배열로 정의
// 회전 함수 12개

// 면 회전 함수 
// 변 회전 함수 -> 회전하는 면에 따라 변이 결정됨! ->> 면의 인덱스 정보를 매개변수로 넘겨주고 switch case 사용...?

// 반시계 회전 = 3번 시계 회전 -> 회전을 2번 더 한다고 복잡도가 올라가진 않으므로 90도 시계 방향 회전으로 구현 통일!

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 0:U(위), 1:D(아래), 2:F(앞), 3:B(뒤), 4:L(왼), 5:R(오른)
// 하양(w), 노랑(y),   빨강(r), 주황(o), 초록(g),  파란(b)
char cube[6][3][3];
char colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

// 큐브 초기화
void init() {
    for (int i = 0; i < 6; i++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                cube[i][r][c] = colors[i];
            }
        }
    }
}

// 면 회전 함수 - 지정한 번호의 면을 90도 시계방향 회전
// 어떻게 두고 보는지 상관 없이 가운데 칸 빼고 다 움직이므로 그냥 회전
void rotateFace(int face) {

    // 임시 배열에 복사
    char tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = cube[face][i][j];

    // 시계 방향 회전: (i, j) -> (j, 2-i)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[face][j][2 - i] = tmp[i][j];
}

// 변 회전 함수 - 지정한 번호의 면의 네 옆변을 90도 시계방향 회전
void rotateSide(int face) {
    char tmp[3];

    switch (face) {

    case 0: //윗면을 바라보고 시계방향으로 90도 돌릴 때, 4개의 옆(3, 5, 2, 4) 상단 변 이동 시뮬레이션

        // B -> R -> F -> L -> B
        // 3 -> 5 -> 2 -> 4 -> 3
        for (int i = 0; i < 3; i++) tmp[i] = cube[3][0][i];             // B 저장
        for (int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i];      // L -> B
        for (int i = 0; i < 3; i++) cube[4][0][i] = cube[2][0][i];      // F -> L
        for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i];      // R -> F
        for (int i = 0; i < 3; i++) cube[5][0][i] = tmp[i];             // B -> R
        break;

    case 1: // 아랫면을 바라보고 시계방향으로 90도 돌릴 때, 4개의 옆(3, 5, 2, 4) 하단 변 이동 시뮬레이션

        // B -> L -> F -> R -> B
        // 3 -> 4 -> 2 -> 5 -> 3
        for (int i = 0; i < 3; i++) tmp[i] = cube[3][2][i];             // B 저장
        for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][2][i];      // R -> B
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[2][2][i];      // F -> R
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2][i];      // L -> F
        for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[i];             // B -> L
        break;

    case 2: // 앞면을 시계방향으로 90도 돌릴 때, 윗면(0)의 아랫변, 오른면(5)의 왼쪽변, 아랫면(1)의 윗변, 왼쪽면(4)의 오른변

        // U -> R -> D -> L -> U
        // 0 -> 5 -> 1 -> 4 -> 0
        for (int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];              // U 저장
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[4][2 - i][2];   // L -> U
        for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][0][i];       // D -> L
        for (int i = 0; i < 3; i++) cube[1][0][i] = cube[5][2 - i][0];   // R -> D
        for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[i];              // U -> R

        break;

    case 3: // 뒷면을 시계방향으로 90도 돌릴 때, 윗면(0)의 윗변, 오른면(5)의 오른변, 아랫면(1)의 아랫변, 왼쪽면(4)의 왼쪽변

        // U -> L -> D -> R -> U
        // 0 -> 4 -> 1 -> 5 -> 0
        for (int i = 0; i < 3; i++) tmp[i] = cube[0][0][i];              // U 저장
        for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2];       // R -> U
        for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][2][2 - i];   // D -> R
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][i][0];       // L -> D
        for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[2 - i];          // U -> L

        break;

    case 4: // 왼쪽면을 시계방향으로 90도 돌릴 때, 윗면(0)의 왼쪽변, 앞면(2)의 왼쪽변, 아랫면(1)의 왼쪽변, 뒤쪽면(3)의 오른변

        // U -> F -> D -> B -> U
        // 0 -> 2 -> 1 -> 3 -> 0
        for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];              // U 저장
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2];   // B -> U
        for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][2 - i][0];   // D -> B
        for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][i][0];       // F -> D
        for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[i];              // U -> F

        break;

    case 5: // 오른쪽면을 시계방향으로 90도 돌릴 때, 윗면(0)의 오른변, 앞면(2)의 오른변, 아랫면(1)의 오른변, 뒤쪽면(3)의 왼변
        
        // U -> B -> D -> F -> U
        // 0 -> 3 -> 1 -> 2 -> 0
        for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][2];              // U 저장
        for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];       // F -> U
        for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][i][2];       // D -> F
        for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][2-i][0];     // B -> D
        for (int i = 0; i < 3; i++) cube[3][2 - i][0] = tmp[i];          // U -> B
        break;

    }
}


// 입력 명령어에 따라 면 회전 및 변 회전을 한번에 처리하는 함수
void process(char face, char dir) {
    int count = (dir == '+') ? 1 : 3; // 시계는 1번, 반시계는 3번 회전
    int fIdx;

    if (face == 'U') fIdx = 0;
    else if (face == 'D') fIdx = 1;
    else if (face == 'F') fIdx = 2;
    else if (face == 'B') fIdx = 3;
    else if (face == 'L') fIdx = 4;
    else if (face == 'R') fIdx = 5;

    while (count--) {
        rotateFace(fIdx); // 면 자체 회전
        rotateSide(fIdx); // 인접 면 회전
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {

        //큐브 초기화
        init();
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            string cmd; cin >> cmd;
            process(cmd[0], cmd[1]);
        }

        // 회전 끝, 윗면 색깔 출력
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }

    }
    return 0;
}
