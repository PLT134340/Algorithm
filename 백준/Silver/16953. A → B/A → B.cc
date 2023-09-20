#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    queue<pair<long long, int>> q; // num, lv
    q.push({a, 1});
    set<int> s;
    s.insert(a);
    while(!q.empty()) {
        auto [num, lv] = q.front();
        q.pop();
        
        if(num == b) {
            cout << lv << '\n';
            return 0;
        }
        
        long long tmp = 2 * num;
        if(tmp <= b && s.find(tmp) == s.end()){ 
            q.push({tmp, lv + 1});
            s.insert(tmp);
        }
        tmp = 10 * num + 1;
        if(tmp <= b && s.find(tmp) == s.end()) {
            q.push({tmp, lv + 1});
            s.insert(tmp);
        }
    }
    
    cout << -1 << "\n";
    return 0;
}