#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int, int>> blank;

void sudoku(int level);

int main() {
    for(int i = 0; i < 9; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 9; j++) {
            arr[i][j] = str[j] - '0';
            if(arr[i][j] == 0)
                blank.push_back({i, j});
        }
    }
    
    sudoku(0);
    return 0;
}

void sudoku(int level) {
    static bool isEnd = false;
    
    if(isEnd)
        return;
    else if(level == blank.size()) {
        isEnd = true;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++)
                cout << arr[i][j];
            cout << '\n';
        }
        return;
    }
    
    auto [y, x] = blank[level];
    for(int i = 1; i <= 9; i++) {
        arr[y][x] = 0;
        
        bool isPromising = true;
        for(int j = 0; isPromising && j < 9; j++)
            if(arr[y][j] == i)
                isPromising = false;
        for(int j = 0; isPromising && j < 9; j++)
            if(arr[j][x] == i)
                isPromising = false;
        int startY = y - y % 3;
        int startX = x - x % 3;
        for(int j = startY; isPromising && j < startY + 3; j++)
            for(int k = startX; isPromising && k < startX + 3; k++)
                if(arr[j][k] == i)
                    isPromising = false;
        
        if(isPromising) {
            arr[y][x] = i;
            sudoku(level + 1);
        }
    }
    
    arr[y][x] = 0;
}