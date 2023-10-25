#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool matrix[1001][1001];
int answer[1001][1001] = {0};
int classification[1001][1001] = {0};
bool isVisited[1001][1001] = {false};
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> zero;
    vector<pair<int, int>> one;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            matrix[i][j] = str[j] - '0';
            if (matrix[i][j] == 0)
                zero.push_back({i, j});
            else
                one.push_back({i, j});
        }
    }

    for (int i = 0; i < zero.size(); i++) {
        stack<pair<int, int>> s;
        if(isVisited[zero[i].first][zero[i].second])
            continue;
        else
            s.push(zero[i]);
        
        isVisited[zero[i].first][zero[i].second] = true;
        vector<pair<int, int>> visited;
        visited.push_back(zero[i]);

        while (!s.empty()) {
            auto [y, x] = s.top();
            s.pop();

            for (int j = 0; j < 4; j++) {
                int newY = y + dy[j];
                int newX = x + dx[j];
                if (newY >= 0 && newY < n && newX >= 0 && newX < m && matrix[newY][newX] == 0 && !isVisited[newY][newX]) {
                    s.push({newY, newX});
                    isVisited[newY][newX] = true;
                    visited.push_back({newY, newX});
                }
            }
        }
        
        static int order = 1;
        int size = visited.size();
        for (int j = 0; j < size; j++) {
            auto [y, x] = visited[j];
            answer[y][x] = size;
            classification[y][x] = order;
        }
        order++;
    }

    for(int i = 0; i < one.size(); i++) {
        auto [y, x] = one[i];
        int sum = 1;
        
        set<int> s;
        for(int j = 0; j < 4; j++) {
            int newY = y + dy[j];
            int newX = x + dx[j];
            if(newY >= 0 && newY < n && newX >= 0 && newX < m && matrix[newY][newX] == 0 && s.find(classification[newY][newX]) == s.end()) {
                sum += answer[newY][newX];
                s.insert(classification[newY][newX]);
            }
        }

        answer[y][x] = sum;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 1)
                cout << answer[i][j] % 10;
            else
                cout << 0;
        cout << '\n';
    }
    return 0;
}