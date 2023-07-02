#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int matrix[500][500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 0};

int bound(vector<pair<int, int>>& v, int max);
bool isVisited(vector<pair<int, int>>& v, int x, int y);

int main() {
    int n, m;
    cin >> n >> m;
    
    int maxNum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > maxNum)
                maxNum = matrix[i][j];
        }
    
    int maxSum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            stack<vector<pair<int, int>>> s;
            s.push(vector<pair<int, int>>(1, {i, j}));
            while(!s.empty()) {
                auto v = s.top();
                s.pop();

                if(v.size() == 4) {
                    int sum = 0;
                    for(auto [y, x] : v)
                        sum += matrix[y][x];
                    if(sum > maxSum)
                        maxSum = sum;
                    continue;
                }

                if(bound(v, maxNum) > maxSum)
                    for(int j = v.size() - 1; j >= 0; j--) {
                        auto [y, x] = v[j];
                        for(int k = 0; k < 4; k++) {
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            
                            if(newX >= 0 && newX < m && newY >= 0 && newY < n
                                && !isVisited(v, newX, newY)) {
                                    auto newV = v;
                                    newV.push_back({newY, newX});
                                    s.push(newV);
                                }
                        }
                    }
            }
        }
    
    cout << maxSum << '\n';
    return 0;
}

int bound(vector<pair<int, int>>& v, int max) {
    int result = 0;
    for(auto [y, x] : v)
        result += matrix[y][x];
    result += max * (4 - v.size());
    return result;
}

bool isVisited(vector<pair<int, int>>& v, int newX, int newY) {
    bool result = false;
    for(auto [y, x] : v)
        if(newX == x && newY == y)
            result = true;
    return result;
}