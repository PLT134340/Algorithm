#include <iostream>
#include <string>
using namespace std;

int whiteFirstSum[2001][2001] = {0};
int blackFirstSum[2001][2001] = {0};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            whiteFirstSum[i][j] = whiteFirstSum[i - 1][j] + whiteFirstSum[i][j - 1] - whiteFirstSum[i - 1][j - 1];
            blackFirstSum[i][j] = blackFirstSum[i - 1][j] + blackFirstSum[i][j - 1] - blackFirstSum[i - 1][j - 1];
            if (str[j - 1] == 'B' && (i % 2 == 1 && j % 2 == 1 || i % 2 == 0 && j % 2 == 0) ||
                str[j - 1] == 'W' && (i % 2 == 1 && j % 2 == 0 || i % 2 == 0 && j % 2 == 1))
                whiteFirstSum[i][j]++;
            if (str[j - 1] == 'W' && (i % 2 == 1 && j % 2 == 1 || i % 2 == 0 && j % 2 == 0) ||
                str[j - 1] == 'B' && (i % 2 == 1 && j % 2 == 0 || i % 2 == 0 && j % 2 == 1))
                blackFirstSum[i][j]++;
        }
    }

    int result = INT32_MAX;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++) {
            int tmp = min(whiteFirstSum[i][j] - whiteFirstSum[i - k][j] - whiteFirstSum[i][j - k] + whiteFirstSum[i - k][j - k],
                          blackFirstSum[i][j] - blackFirstSum[i - k][j] - blackFirstSum[i][j - k] + blackFirstSum[i - k][j - k]);
            if (result > tmp)
                result = tmp;
        }
    cout << result << '\n';
    return 0;
}