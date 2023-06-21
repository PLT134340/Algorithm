#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, string> name;
    unordered_map<string, int> number;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        name.insert({i + 1, tmp});
        number.insert({tmp, i + 1});
    }

    for(int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if(isdigit(tmp[0]))
            cout << name[stoi(tmp)] << '\n';
        else 
            cout << number[tmp] << '\n';
    }
    return 0;
}
