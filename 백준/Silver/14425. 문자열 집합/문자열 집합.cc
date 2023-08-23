#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> hs;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        hs.insert(str);
    }

    int result = 0;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if(hs.find(str) != hs.end())
            result++;
    }

    cout << result << '\n';
    return 0;
}