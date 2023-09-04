#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<string>> v(2);
    v[1].push_back("  *  ");
    v[1].push_back(" * * ");
    v[1].push_back("*****");

    int size = 3;
    for (int i = 2; size < n; i++, size *= 2) {
        v.push_back(vector<string>());
        string tmp = string(size, ' ');
        for (int j = 0; j < size; j++)
            v[i].push_back(tmp + v[i - 1][j] + tmp);
        for (int j = 0; j < size; j++)
            v[i].push_back(v[i - 1][j] + " " + v[i - 1][j]);
    }

    for (int i = 0; i < v.back().size(); i++)
        cout << v.back()[i] << '\n';
    return 0;
}