#include <iostream>
#include <vector>
#include <string>
using namespace std;

char arr[6561][6561];

void pattern(int n, int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = '*';

    pattern(n, 0, 0);
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}

void pattern(int n, int y, int x) {
    if(n == 1)
        return;
    
    int next = n / 3;
    for(int i = 0; i < next; i++)
        for(int j = 0; j < next; j++)
            arr[y + next + i][x + next + j] = ' ';
    
    for(int i = 0; i < 3; i++) {
        int nextY = y + i * next;
        for(int j = 0; j < 3; j++) {
            int nextX = x + j * next;
            pattern(next, nextY, nextX);
        }
    }
}