#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<string> s;
    for(int i = 0; i < n; i++) {
        string name, access;
        cin >> name >> access;
        if(access == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    for(auto it = s.rbegin(); it != s.rend(); it++)
        cout << *it << '\n';
    return 0;
}