#include <iostream>
using namespace std;

int a[100][100];
int b[100][100];
int result[100][100] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int k;
    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int l = 0; l < m; l++)
                result[i][j] += a[i][l] * b[l][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}