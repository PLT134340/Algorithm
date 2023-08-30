#include <iostream>
using namespace std;

int arr[2187][2187];
int numOfPaper[3] = {0};

void cutPaper(int n, int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cutPaper(n, 0, 0);

    for (int i = 0; i < 3; i++)
        cout << numOfPaper[i] << '\n';
    return 0;
}

void cutPaper(int n, int y, int x) {
    if (n == 1) {
        numOfPaper[arr[y][x] + 1]++;
        return;
    }

    int prevNum = arr[y][x];
    bool isSame = true;
    for (int i = 0; i < n; i++)
        if (isSame)
            for (int j = 0; j < n; j++)
                if (prevNum != arr[y + i][x + j]) {
                    isSame = false;
                    break;
                }

    if (isSame)
        numOfPaper[arr[y][x] + 1]++;
    else
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int newN = n / 3;
                cutPaper(newN, y + i * newN, x + j * newN);
            }
}