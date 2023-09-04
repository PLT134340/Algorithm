#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

const int INF = 1000000000;

int dijkstra(vector<vector<pair<int, int>>> &edges, int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;
    cout << dijkstra(edges, start, end);
    return 0;
}

int dijkstra(vector<vector<pair<int, int>>> &edges, int start, int end) {
    int distance[1001];
    for (int i = 0; i < 1001; i++)
        distance[i] = INF;
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        auto [vertex, cost] = pq.top();
        pq.pop();

        if (distance[vertex] >= cost)
            for (int i = 0; i < edges[vertex].size(); i++) {
                auto [nextVertex, weight] = edges[vertex][i];
                int newCost = distance[vertex] + weight;
                if (distance[nextVertex] > newCost) {
                    distance[nextVertex] = newCost;
                    pq.push({nextVertex, newCost});
                }
            }
    }
    return distance[end];
}