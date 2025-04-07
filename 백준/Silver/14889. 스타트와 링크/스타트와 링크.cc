#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int N;
int mn = INT_MAX;
int s[20][20];
bool visited[20] {false, };

void calculateScore() {
    int start_score = 0;
    int link_score = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i] && visited[j]) start_score += s[i][j];
            else if(!visited[i] && !visited[j]) link_score += s[i][j];
        }
    }
    mn = min(mn, abs(start_score - link_score));
}

void solve(int step, int cur) {
    if(step == N / 2) { // terminate case
        calculateScore();
        return;
    }
    
    //avg case
    for(int i = cur; i < N; i++) {
        visited[i] = true;
        solve(step + 1, i + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //input
    cin >> N; 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }
    
    //solve
    solve(0, 0);
    cout << mn << '\n';
    return 0;
    
}