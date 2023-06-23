#include <iostream>
using namespace std;

bool matrix[128][128] = {false};

void next(int n, int x, int y, int& white, int& blue);

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    int white = 0;
    int blue = 0;
    next(n, 0, 0, white, blue);
    cout << white << endl << blue << endl;
    return 0;
}

void next(int n, int x, int y, int& white, int& blue) {
    if(n == 0)
        return;
    
    bool isWhite = true;
    bool isBlue = true;
    for(int i = y; i < y + n; i++)
        for(int j = x; j < x + n; j++)
            if(matrix[i][j] == 1)
                isWhite = false;
            else
                isBlue = false;
    
    if(isWhite) {
        white++;
        return;
    } else if(isBlue) {
        blue++;
        return;
    } else {
        next(n / 2, x, y, white, blue);
        next(n / 2, x + n / 2, y, white, blue);
        next(n / 2, x, y + n / 2, white, blue);
        next(n / 2, x + n / 2, y + n / 2, white, blue);
    }
}