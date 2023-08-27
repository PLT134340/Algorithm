#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int board[9][9] = {0};
vector<pair<int, int>> blank;

void sdoku(int n);
bool rowSearch(int y, int x);
bool colSearch(int y, int x);
bool sqrSearch(int y, int x);
void printBoard();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0)
                blank.push_back({i, j});
        }
    
    if(blank.size() == 0) {
        printBoard();
        return 0;
    }
    
    sdoku(0);
    return 0;
}

void sdoku(int n) {
    static bool isEnd = false;
    if(n == blank.size()) {
        isEnd = true;
        printBoard();
        return;
    }

    auto [y, x] = blank[n];
    for(int i = 1; i <= 9; i++) {
        board[y][x] = i;
        if(!isEnd && rowSearch(y, x) && colSearch(y, x) && sqrSearch(y, x))
            sdoku(n + 1);
    }
    board[y][x] = 0;
}

bool rowSearch(int y, int x) {
    int count[10] = {0};
    for(int i = 0; i < 9; i++)
        if(count[board[y][i]] == 0 || board[y][i] == 0)
            count[board[y][i]]++;
        else
            return false;
    return true;
}

bool colSearch(int y, int x) {
    int count[10] = {0};
    for(int i = 0; i < 9; i++)
        if(count[board[i][x]] == 0 || board[i][x] == 0)
            count[board[i][x]]++;
        else
            return false;
    return true;
}

bool sqrSearch(int y, int x) {
    int count[10] = {0};
    int sqrY = y - y % 3;
    int sqrX = x - x % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(count[board[sqrY + i][sqrX + j]] == 0 || board[sqrY + i][sqrX + j] == 0)
                count[board[sqrY + i][sqrX + j]]++;
            else
                return false;
    return true;
}

void printBoard() {
    int count = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}