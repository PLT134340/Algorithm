#include <iostream>
#include <vector>
#include <queue>
#define inf 10000000
using namespace std;


void dijkstra(vector<vector<pair<int, int>>>& edge, int start, int num, vector<int>& result);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e, k;
    cin >> v >> e >> k;

    vector<vector<pair<int, int>>> edge(v + 1);
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    vector<int> result(v + 1, inf);
    dijkstra(edge, k, v, result);

    for(int i = 1; i <= v; i++)
        if(result[i] == inf)
            cout << "INF" << '\n';
        else
            cout << result[i] << '\n';
    return 0;
}

void dijkstra(vector<vector<pair<int, int>>>& edge, int start, int num, vector<int>& result) {
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