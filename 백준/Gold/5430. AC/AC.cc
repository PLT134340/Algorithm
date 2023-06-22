#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string funct, arr;
        int n;
        cin >> funct >> n >> arr;

        list<int> l;
        string tmp = "";
        for(int j = 0; j < arr.length(); j++) {
            if(isdigit(arr[j]))
                tmp += string(1, arr[j]);
            else if(arr[j] == ',' || arr[j] == ']') {
                if(tmp != "")
                    l.push_back(stoi(tmp));
                tmp = "";
            }
        }

        bool isReverse = false;
        bool isError = false;
        int length = funct.length();
        for(int j = 0; j < length; j++)
            if(funct[j] == 'R')
                isReverse = !isReverse;
            else if(l.empty()) {
                cout << "error" << '\n';
                isError = true;
                break;
            } else if(isReverse)
                l.pop_back();
            else
                l.pop_front();
        if(isError)
            continue;
        if(isReverse)
            l.reverse();

        cout << '[';
        auto it = l.begin();
        if(!l.empty()) {
            cout << *it;
            it++;
        }
        for(; it != l.end(); it++)
            cout << ',' << *it;
        cout << ']' << '\n';
    }
    return 0;
}