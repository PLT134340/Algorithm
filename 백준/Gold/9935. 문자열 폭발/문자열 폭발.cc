#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, bomb;
    cin >> str >> bomb;
    int strLength = str.size();
    int bombLength = bomb.size();

    list<char> l;
    for(int i = 0; i < strLength; i++)
        l.push_back(str[i]);

    int count = 0;
    stack<int> s;
    for(auto it = l.begin(); it != l.end(); it++) {
        char c = *it;
        if(c == bomb[count])
            count++;
        else if(c == bomb[0]) {
            s.push(count);
            count = 1;
        } else {
            while(!s.empty())
                s.pop();
            count = 0;
        }

        if(count == bombLength) {
            for(int i = 0; i < count; i++) {
                it = l.erase(it);
                it--;
            }

            if(!s.empty()) {
                count = s.top();
                s.pop();
            } else
                count = 0;
        }
    }
    
    if(l.empty())
        cout << "FRULA" << '\n';
    else {
        for(auto it = l.begin(); it != l.end(); it++)
            cout << *it;
        cout << '\n';
    }
    return 0;
}