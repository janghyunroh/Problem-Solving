#include <iostream>

using namespace std;

int main() 
{
    string str; cin >> str;
    int sm = 0;
    int checkIdx;
    int multiplier = 1;
    for(int i = 0; i < str.size(); i++) {
        int mul = (i % 2 == 0 ? 1 : 3);
        char c = str[i];
        
        // 훼손된 문자인 경우
        if(c=='*') {
            multiplier = mul;
            continue; 
        }
        
        int n = int(c-int('0'));
        sm = (sm + (mul * n)) % 10;
    }

    if(multiplier == 1) cout << (10 - sm) % 10;
    else {
        for(int i = 0; i <= 9; i++) {
            if((i * 3) % 10 == ((10 - sm) % 10)) cout << i;
        }
    }
    return 0;
}
