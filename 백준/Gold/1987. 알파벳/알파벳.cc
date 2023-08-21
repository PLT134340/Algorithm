#include <iostream>
#include <string>
#include <set>
using namespace std;

int r, c;
char board[20][20];
bool alp[26] = {false};
int result = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void maxCount(int y, int x, int lv);

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < c; j++)
            board[i][j] = str[j];
    }

    alp[board[0][0] - 'A'] = true;
    maxCount(0, 0, 1);
    cout << result << '\n';
    return 0;
}

void maxCount(int y, int x, int lv) {
    if(result < lv)
        result = lv;
    
    for(int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(newY >= 0 && newY < r && newX >= 0 && newX < c && !alp[board[newY][newX] - 'A']) {
            alp[board[newY][newX] - 'A'] = true;
            maxCount(newY, newX, lv + 1);
        }
    }

    alp[board[y][x] - 'A'] = false;
}