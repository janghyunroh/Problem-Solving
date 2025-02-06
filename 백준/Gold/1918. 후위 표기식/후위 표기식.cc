/*
연산자 종류 및 우선 순위
1. (, )
2. *, /
3. +, -

중위표기식 -> 괄호 넣은 중위 표기식 -> 후위표기식
연산자를 스택에 넣기

1. 피연산자는 바로 출력
2. 연산자를 마주치는 경우
    1) 스택이 비어있는 경우 -> 스택에 연산자 넣기
    2) 스택이 비어있지 않은 경우
        1) 스택의 top 연산자보다 우선순위가 높은 경우 -> 스택에 연산자 넣기
        2) 스택의 top 연산자보다 우선순위가 낮은 경우 -> 스택의 top 연산자 출력 후 스택에 연산자 넣기
3. 괄호를 마주치는 경우
    1) 여는 괄호인 경우 -> 스택에 넣기
    2) 닫는 괄호인 경우 -> 여는 괄호를 만날 때까지 스택의 연산자 출력

*후위 표기식은 괄호가 필요 없음 -> 괄호 출력 X

*/

#include <iostream>
#include <stack>

using namespace std;

string str;
stack <char> st;

int main() {
    cin >> str;
    for(char c : str) {

        //1. 피연산자인 경우
        if('A' <= c && c <= 'Z') cout << c;

        //2. 연산자/괄호인 경우
        else {

            //여는 괄호인 경우
            if(c == '(') st.push(c);

            //연산자 ( *, / ) 인 경우
            else if(c == '*' || c == '/') {
                while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }

            //연산자 ( +, - ) 인 경우
            else if(c == '+' || c == '-') {
                while(!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }

            //닫는 괄호인 경우
            else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }

    //스택에 남아있는 연산자 출력
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}