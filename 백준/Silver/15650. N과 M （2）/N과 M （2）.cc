#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<vector<int>> q;
    for(int i = 1; i <= n; i++) {
        vector<int> v;
        v.push_back(i);
        q.push(v);
    }

    while(!q.empty()) {
        auto v = q.front();
        q.pop();

        if(v.size() == m) {
            for(auto item : v)
                cout << item << ' ';
            cout << '\n';
        } else
            for(int i = v.back() + 1; i <= n; i++) {
                auto newV = v;
                newV.push_back(i);
                q.push(newV);
            }
    }
    return 0;
}