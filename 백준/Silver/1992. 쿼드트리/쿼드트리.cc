#include <iostream>
#include <string>
using namespace std;

char arr[64][64];

string quadTree(int n, int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            if (str[j] == '1')
                arr[i][j] = '1';
            else
                arr[i][j] = '0';
    }

    cout << quadTree(n, 0, 0) << '\n';
    return 0;
}

string quadTree(int n, int y, int x) {
    if (n == 1)
        return string(1, arr[y][x]);

    string upperLeft = quadTree(n / 2, y, x);
    string upperRight = quadTree(n / 2, y, x + n / 2);
    string lowerLeft = quadTree(n / 2, y + n / 2, x);
    string lowerRight = quadTree(n / 2, y + n / 2, x + n / 2);

    if (upperLeft == "1" && upperRight == "1" && lowerLeft == "1" && lowerRight == "1")
        return "1";
    else if (upperLeft == "0" && upperRight == "0" && lowerLeft == "0" && lowerRight == "0")
        return "0";
    else
        return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}