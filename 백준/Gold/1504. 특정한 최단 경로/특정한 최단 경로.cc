#include <iostream>
#include <queue>
#include <vector>
#define INF 100000000
using namespace std;

struct compare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

int dijkstra(vector<vector<pair<int, int>>> &edges, int start, int end);

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int mid = dijkstra(edges, v1, v2);

    int from1toV1 = dijkstra(edges, 1, v1);
    int from1toV2 = dijkstra(edges, 1, v2);
    int fromV1toN = dijkstra(edges, v1, n);
    int fromV2toN = dijkstra(edges, v2, n);

    int result1 = dijkstra(edges, 1, v1) + mid + dijkstra(edges, v2, n);
    int result2 = dijkstra(edges, 1, v2) + mid + dijkstra(edges, v1, n);

    if (result1 >= INF && result2 >= INF)
        cout << -1 << '\n';
    else
        cout << min(result1, result2) << '\n';
    return 0;
}

int dijkstra(vector<vector<pair<int, int>>> &edges, int start, int end) {
    int distance[801];
    for (int i = 0; i < 801; i++)
        distance[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({start, 0});
    distance[start] = 0;
    
    while(!pq.empty()) {
        auto [vertex, cost] = pq.top();
        pq.pop();
        
        if(distance[vertex] >= cost)
            for(int i = 0; i < edges[vertex].size(); i++) {
                auto [nextVertex, weight] = edges[vertex][i];
                int newCost = cost + weight;
                if(newCost < distance[nextVertex]) {
                    distance[nextVertex] = newCost;
                    pq.push({nextVertex, newCost});
                }
            }
    }
    return distance[end];
}