#include <iostream>
#include <string>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

bool matrix[25][25] = {false};
bool isVisited[25][25] = {false};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n;
    cin >> n;

    stack<tuple<int, int, bool>> s;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            if(str[j] == '1') {
                matrix[i][j] = true;
                s.push({i, j, true});
            }
        }
    }
    vector<int> v;
    int total = -1;
    while(!s.empty()) {
        auto [y, x, isNew] = s.top();
        s.pop();

        if(!isVisited[y][x] && isNew) {
            isVisited[y][x] = true;
            total++;
            v.push_back(1);
        }
        
        for(int i = 0; i < 4; i++)
            if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n
                && !isVisited[y + dy[i]][x + dx[i]] && matrix[y + dy[i]][x + dx[i]] == 1) {
                s.push(make_tuple(y + dy[i], x + dx[i], false));
                isVisited[y + dy[i]][x + dx[i]] = true;
                v[total]++;
            }
    }

    cout << total + 1 << '\n';
    sort(v.begin(), v.end());
    for(auto elem : v)
        cout << elem << '\n';
    return 0;
}