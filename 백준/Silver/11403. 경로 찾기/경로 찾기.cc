#include <iostream>
#include <stack>
using namespace std;

bool edge[100][100] = {false};
bool result[100][100] = {false};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> edge[i][j];
            if(edge[i][j])
                s.push({i, j});
        }
    
    while(!s.empty()) {
        auto [start, end] = s.top();
        s.pop();
        
        if(!result[start][end])
            result[start][end] = true;
        else
            continue;

        for(int i = 0; i < n; i++)
            if(edge[end][i])
                s.push({start, i});
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}