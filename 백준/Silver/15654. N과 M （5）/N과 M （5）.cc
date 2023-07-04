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
        } else {
            auto etcV = v;
            for(int i = 0; i < vec.size(); i++)
                etcV.erase(remove(etcV.begin(), etcV.end(), vec[i]), etcV.end());
            
            for(int i = 0; i < etcV.size(); i++) {
                auto newV = vec;
                newV.push_back(etcV[i]);
                q.push(newV);
            }
        }       
    }
    return 0;
}