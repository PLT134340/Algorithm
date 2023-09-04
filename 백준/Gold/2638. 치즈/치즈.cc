#include <iostream>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int graph[102][102] = {0};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    queue<pair<int, int>> cheese;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 1)
                cheese.push({i, j});
        }
    
    set<pair<int, int>> air;
    stack<pair<int, int>> s;
    air.insert({0, 0});
    s.push({0, 0});
    while(!s.empty()) {
        auto [y, x] = s.top();
        s.pop();
        
        for(int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(newY >= 0 && newY <= n + 1 && newX >= 0 && newX <= m + 1 && graph[newY][newX] == 0 && air.find({newY, newX}) == air.end()) {
                air.insert({newY, newX});
                s.push({newY, newX});
            }
        }
    }
    
    int result = 0;
    while(cheese.size() != 0) {
        queue<pair<int, int>> newAir;
        int size = cheese.size();
        for(int i = 0; i < size; i++) {
            auto [y, x] = cheese.front();
            cheese.pop();
            
            int side = 0;
            for(int j = 0; j < 4; j++) {
                int newY = y + dy[j];
                int newX = x + dx[j];
                if(air.find({newY, newX}) != air.end())
                    side++;
            }
            if(side >= 2) 
                newAir.push({y, x});
            else
                cheese.push({y, x});
        }
        
        while(!newAir.empty()) {
            air.insert(newAir.front());
            s.push(newAir.front());
            auto [y, x] = newAir.front();
            newAir.pop();
            graph[y][x] = 0;
        }
        while(!s.empty()) {
            auto [y, x] = s.top();
            s.pop();
            
            for(int i = 0; i < 4; i++) {
                int newY = y + dy[i];
                int newX = x + dx[i];
                if(newY >= 0 && newY <= n + 1 && newX >= 0 && newX <= m + 1 && graph[newY][newX] == 0 && air.find({newY, newX}) == air.end()) {
                    air.insert({newY, newX});
                    s.push({newY, newX});
                }
            }
        }
        
        result++;
    }
    
    cout << result << '\n';
    return 0;
}