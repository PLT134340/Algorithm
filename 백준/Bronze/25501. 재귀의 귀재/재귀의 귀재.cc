#include <iostream>
#include <string>
using namespace std;

void palindrome(string s){
    int count = 0;
    int length = s.size();
    for(int i = 0; i <= length / 2; i++) {
        count++; 
        if(s[i] != s[length - 1 - i]) {
            cout << 0 << ' ' << count << '\n';
            return;
        }
    }
    cout << 1 << ' ' << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string str;
        cin >> str;
        palindrome(str);
    }
    return 0;
}