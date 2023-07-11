#include <iostream>
#include <vector>
#include <set>
#define inf 10000000
using namespace std;

int edge[1001][1001];
int rvsEdge[1001][1001];
int fromDest[1001];
int toDest[1001];

void dijkstra(int start, int n, int edge[][1001], int result[]);
void print(int n, int result[]);

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            edge[i][j] = rvsEdge[i][j] = inf;

    for(int i = 0; i < m; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        edge[start][end] = time;
        rvsEdge[end][start] = time;
    }

    dijkstra(x, n, edge, fromDest);
    dijkstra(x, n, rvsEdge, toDest);

    int max = 0;
    for(int i = 1; i <= n; i++)
        if(max < fromDest[i] + toDest[i])
            max = fromDest[i] + toDest[i];
    cout << max << '\n';
    return 0;
}

void dijkstra(int start, int n, int edge[][1001], int result[]) {
    set<int> s;
    s.insert(start);
    int vertex[1001] = {0};
    int length[1001] = {0};
    for(int i = 1; i <= n; i++)
        length[i] = inf;
    
    int nextVertex = start;
    s.insert(nextVertex);
    while(s.size() != n) {
        for(int i = 1; i <= n; i++)
            if(s.find(i) == s.end() && length[i] > result[nextVertex] + edge[nextVertex][i]) {
                vertex[i] = nextVertex;
                length[i] = result[nextVertex] + edge[nextVertex][i];
            }
        
        int min = inf;
        for(int i = 1; i <= n; i++)
            if(s.find(i) == s.end() && min > length[i]) {
                min = length[i];
                nextVertex = i;
            }
        result[nextVertex] = length[nextVertex];
        s.insert(nextVertex);
    }
}

void print(int n, int result[]) {
    for(int i = 1; i <= n; i++)
        cout << i << ":\t" << result[i] << '\n';
    cout << '\n';
}