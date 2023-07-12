#include <iostream>
#include <vector>
#include <queue>
#define inf 10000000
using namespace std;


void dijkstra(vector<vector<pair<int, int>>>& edge, int start, int n, vector<int>& result);

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> edge(n + 1);
    vector<vector<pair<int, int>>> rvsEdge(n + 1);
    for(int i = 0; i < m; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        edge[start].push_back({end, time});
        rvsEdge[end].push_back({start, time});
    }

    vector<int> fromDest;
    vector<int> toDest;
    dijkstra(edge, x, n, fromDest);
    dijkstra(rvsEdge, x, n, toDest);

    int max = 0;
    for(int i = 1; i <= n; i++)
        if(max < fromDest[i] + toDest[i])
            max = fromDest[i] + toDest[i];
    cout << max << '\n';
    return 0;
}

void dijkstra(vector<vector<pair<int, int>>>& edge, int start, int num, vector<int>& result) {
    result.assign(num + 1, inf);
    result[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();
        
        for(int i = 0; i < edge[vertex].size(); i++) {
            auto [nextVertex, nextWeight] = edge[vertex][i];

            if(result[nextVertex] > weight + nextWeight) {
                result[nextVertex] = weight + nextWeight;
                pq.push({weight + nextWeight, nextVertex});
            }
        }
    }
}