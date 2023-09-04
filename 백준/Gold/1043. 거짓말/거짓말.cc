#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main() {
    int n, m, num;
    cin >> n >> m >> num;
    
    set<int> s;
    queue<int> q;
    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    vector<set<int>> v(m);
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) {
            int tmp;
            cin >> tmp;
            v[i].insert(tmp);
        }
    }
    
    bool arr[50] = {false};
    for(int i = 0; i < m; i++)
        arr[i] = true;
    
    while(!q.empty()) {
        int present = q.front();
        q.pop();
        
        for(int i = 0; i < v.size(); i++)
            if(arr[i] && v[i].find(present) != v[i].end()) {
                arr[i] = false;
                for(auto it = v[i].begin(); it != v[i].end(); it++)
                    if(s.find(*it) == s.end()) {
                        s.insert(*it);
                        q.push(*it);
                    }
            }
    }
    
    int result = 0;
    for(int i = 0; i < m; i++)
        if(arr[i])
            result++;
    cout << result << '\n';
    return 0;
}