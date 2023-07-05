#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> uv = v;
    uv.erase(unique(uv.begin(), uv.end()), uv.end());

    queue<vector<int>> q;
    for(int i = 0; i < uv.size(); i++)
        q.push(vector<int>(1, uv[i]));
    while(!q.empty()) {
        auto vec = q.front();
        q.pop();

        if(vec.size() == m) {
            for(auto item : vec)
                cout << item << ' ';
            cout << '\n';
        } else {
            auto etcV = v;
            for(auto item : vec)
                for(auto it = etcV.begin(); it != etcV.end();)
                    if(*it == item) {
                        etcV.erase(it);
                        break;
                    } else
                        it++;
            
            etcV.erase(unique(etcV.begin(), etcV.end()), etcV.end());
            for(auto item: etcV) {
                auto newV = vec;
                newV.push_back(item);
                q.push(newV);
            }
        }
    }
    return 0;
}