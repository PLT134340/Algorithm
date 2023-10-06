#include <iostream>
using namespace std;

const int INF = 1000000000;

int numItem[101];
int edges[101][101];

void floyd(int n);

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) 
        cin >> numItem[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            edges[i][j] = INF;
        edges[i][i] = 0;
    }
    
    for(int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        edges[a][b] = l;
        edges[b][a] = l;
    }
    
    floyd(n);
    
    int result = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++)
            if(edges[i][j] <= m)
                sum += numItem[j];
        if(result < sum)
            result = sum;
    }
    
    cout << result << '\n';
    return 0;
}

void floyd(int n) {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(edges[i][j] > edges[i][k] + edges[k][j])
                    edges[i][j] = edges[i][k] + edges[k][j];
}