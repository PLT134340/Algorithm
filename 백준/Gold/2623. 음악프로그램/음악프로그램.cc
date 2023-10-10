#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> outgoing(n + 1);
    vector<int> incoming(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        
        int prev = 0;
        for(int j = 0; j < t; j++) {
            int tmp;
            cin >> tmp;
            if(prev != 0) {
                outgoing[prev].push_back(tmp);
                incoming[tmp]++;
            }
            prev = tmp;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(incoming[i] == 0)
            q.push(i);
    vector<int> answer;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        answer.push_back(num);
        
        int size = outgoing[num].size();
        for(int i = 0; i < size; i++) {
            int tmp = outgoing[num][i];
            incoming[tmp]--;
            if(incoming[tmp] == 0)
                q.push(tmp);
        }
    }
    
    if(answer.size() == n)
        for(auto elem : answer)
            cout << elem << '\n';
    else
        cout << 0 << '\n';
    return 0;
}