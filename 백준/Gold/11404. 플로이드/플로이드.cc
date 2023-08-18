#include <iostream>
#include <vector>
using namespace std;

#define inf 100000000

void floyd(vector<vector<int>>& v, int size);

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(n + 1, inf));
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(v[a][b] > c)
            v[a][b] = c;
    }
    for(int i = 1; i <= n; i++)
        v[i][i] = 0;

    floyd(v, n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(v[i][j] != inf)
                cout << v[i][j] << ' ';
            else
                cout << 0 << ' ';
        cout << '\n';
    }

    return 0;
}

void floyd(vector<vector<int>>& v, int size) {
    for(int k = 1; k <= size; k++)
        for(int i = 1; i <= size; i++)
            for(int j = 1; j <= size; j++)
                if(v[i][j] > v[i][k] + v[k][j])
                    v[i][j] = v[i][k] + v[k][j];
}