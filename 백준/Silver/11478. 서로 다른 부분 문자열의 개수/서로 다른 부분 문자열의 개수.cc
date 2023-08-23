#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    unordered_set<string> hs;
    for(int i = 1; i <= s.size(); i++)
        for(int j = 0; j <= s.size() - i; j++)
            hs.insert(s.substr(j, i));

    cout << hs.size() << '\n';
    return 0;
}