#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    queue<vector<int>> q;
    for(int i = 0; i < n; i++) {
        vector<int> vec;
        vec.push_back(v[i]);
        q.push(vec);
    }

    while(!q.empty()) {
        auto vec = q.front();
        q.pop();

        if(vec.size() == m) {
            for(auto item : vec)
                cout << item << ' ';
            cout << '\n';
        } else
            for(auto it = find(v.begin(), v.end(), vec.back()); it != v.end(); it++) {
                auto newV = vec;
                newV.push_back(v[it - v.begin()]);
                q.push(newV);
            }
    }
    return 0;
}