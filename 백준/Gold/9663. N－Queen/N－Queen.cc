#include <iostream>
#include <vector>
using namespace std;

int arr[15] = {0};

int nQueen(int x, int n);
bool isPromising(int col, int level);

int main() {
    int n;
    cin >> n;
    
    cout << nQueen(0, n) << endl;
    return 0;
}

int nQueen(int x, int n) {
    static int count = 0;
    if(x == n)
        count++;

    for(int i = 0; i < n; i++)
        if(isPromising(i, x)) {
            arr[x] = i;
            nQueen(x + 1, n);
        }
    
    return count;
}

bool isPromising(int col, int level) {
    for(int i = 0; i < level; i++) // (i, arr[i]), (level, col)
        if(arr[i] == col || level - i == abs(col - arr[i]))
            return false;
    return true;
}