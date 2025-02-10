#include <iostream>
#include <deque>
#include <string>

using namespace std;   

int T, N;
deque<int> dq;
bool reversed;
void R() {
    reversed = !reversed;
}

void D() {
    //dq의 첫번째 원소 삭제
    if(reversed) dq.pop_back();
    else dq.pop_front();
}

int main() {
    cin >> T;
    while(T--) { 
        reversed = false;
        dq = deque<int>();
        string p; cin >> p;
        cin >> N;
        string arr; cin >> arr;

        //parsing arr([a, b, c, ...]꼴을 deque에 넣기)
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == '[' || arr[i] == ']' || arr[i] == ',') continue;
            else {
                string x = "";
                //x가 한자리수가 아닐 수 있으므로 숫자가 끝날 때까지 읽어야 함
                while(arr[i] != ',' && arr[i] != ']') {
                    x += arr[i];
                    i++;
                }
                int n = stoi(x);
                dq.push_back(n);
            }
        }

        //

        //p 과정 수행
        bool err = false;
        for(char c : p) {
            if(c == 'R') R();
            else if(c == 'D') {
                if(dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }
                else D();
            }
        }
        if(!err) {
            //
            cout << "[";

            if(reversed) {
                while(!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ",";
                }
            }

            else {
                while(!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ",";
                }
            }
            
            
            cout << "]\n";
        }
    }
    return 0;
}