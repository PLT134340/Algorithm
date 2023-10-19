#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int h, w;
char plan[102][102];
set<char> key;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void inputMap();
void inputKey();
void searchMap(queue<pair<int, int>> &q, vector<vector<bool>> &isVisited, int &result);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> w;
        inputMap();
        inputKey();

        vector<vector<bool>> isVisited(h + 2, vector<bool>(w + 2, false));
        isVisited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int result = 0;
        searchMap(q, isVisited, result);
        cout << result << '\n';
        
        key.clear();
    }
    return 0;
}

void inputMap() {
    for (int i = 0; i <= w + 1; i++)
        plan[0][i] = plan[h + 1][i] = '.';
    for (int i = 1; i <= h; i++)
        plan[i][0] = plan[i][w + 1] = '.';

    for (int i = 1; i <= h; i++) {
        string str;
        cin >> str;
        if(str != "0")
            for (int j = 1; j <= w; j++)
                plan[i][j] = str[j - 1];
    }
}

void inputKey() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        key.insert(str[i] - 'a' + 'A');
}

void searchMap(queue<pair<int, int>> &q, vector<vector<bool>> &isVisited, int &result) {
    bool isNew = false;

    queue<pair<int, int>> nextQ;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        if (plan[y][x] >= 'A' && plan[y][x] <= 'Z' && key.find(plan[y][x]) == key.end()) {
            nextQ.push({y, x});
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (newY >= 0 && newY <= h + 1 && newX >= 0 && newX <= w + 1 && !isVisited[newY][newX] && plan[newY][newX] != '*') {
                q.push({newY, newX});
                isVisited[newY][newX] = true;
                isNew = true;
                
                if (plan[newY][newX] == '$')
                    result++;
                else if (plan[newY][newX] >= 'a' && plan[newY][newX] <= 'z')
                    key.insert(plan[newY][newX] - 'a' + 'A');
            }
        }
    }

    if (isNew)
        searchMap(nextQ, isVisited, result);
}