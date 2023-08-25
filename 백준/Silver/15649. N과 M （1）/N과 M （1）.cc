#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
            for(int i = 0; i < v.size(); i++)
                cout << v[i] << ' ';
            cout << '\n';
            continue;
        }
        
        for(int i = 1; i <= n; i++) {
            bool isSatisfy = true;
            for(int j = 0; j < v.size(); j++)
                if(i == v[j]) {
                    isSatisfy = false;
                    break;
                }
            
            if(isSatisfy) {
                auto newV = v;
                newV.push_back(i);
                q.push(newV);
            }
        }
    }
    return 0;
}