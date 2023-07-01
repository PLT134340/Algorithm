#include <iostream>
#include <string>
#include <stack>
#include <tuple>
using namespace std;

char matrix[100][100];
bool isVisited[100][100] = {false};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n;
    cin >> n;

    stack<tuple<int, int, char, int>> s1;
    stack<tuple<int, int, char, int>> s2;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            matrix[i][j] = str[j];
            s1.push(make_tuple(i, j, str[j], 0));
            s2.push(make_tuple(i, j, str[j], 0));
        }
    }

    int result1 = 0;
    while(!s1.empty()) {
        auto [y, x, color, lv] = s1.top();
        s1.pop();

        if(!isVisited[y][x]) {
            isVisited[y][x] = true;
            if(lv == 0)
                result1++;
        } else
            continue;

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < n && newY >= 0 && newY < n
                && color == matrix[newY][newX] && !isVisited[newY][newX])
                s1.push(make_tuple(newY, newX, color, lv + 1));
        }
    }

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            isVisited[i][j] = false;

    int result2 = 0;
    while(!s2.empty()) {
        auto [y, x, color, lv] = s2.top();
        s2.pop();

        if(!isVisited[y][x]) {
            isVisited[y][x] = true;
            if(lv == 0)
                result2++;
        } else
            continue;

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < n && newY >= 0 && newY < n
                && (color == matrix[newY][newX]
                || color == 'R' && matrix[newY][newX] == 'G' || color == 'G' && matrix[newY][newX] == 'R')
                && !isVisited[newY][newX])
                s2.push(make_tuple(newY, newX, color, lv + 1));
        }
    }

    cout << result1 << ' ' << result2 << '\n';
    return 0;
}