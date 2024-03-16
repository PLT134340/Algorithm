#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int weight;
};

struct compare {
    const bool operator()(const Edge &e1, const Edge &e2) const {
        return e1.weight > e2.weight;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> edge(n + 1, vector<Edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(Edge{b, c});
        edge[b].push_back(Edge{a, c});
    }
    
    vector<bool> is_visited(n + 1, false);
    is_visited[1] = true;
    
    priority_queue<Edge, vector<Edge>, compare> pq;
    for (int i = 0; i < edge[1].size(); i++)
        pq.push(edge[1][i]);
        
    vector<int> tree_edges;
    while (!pq.empty()) {
        auto [to, weight] = pq.top();
        pq.pop();
        
        if (is_visited[to])
            continue;
        
        is_visited[to] = true;
        tree_edges.push_back(weight);
        
        for (int i = 0; i < edge[to].size(); i++)
            pq.push(edge[to][i]);
    }
    
    int max = 0;
    int sum = 0;
    for (int i = 0; i < tree_edges.size(); i++) {
        sum += tree_edges[i];
        if (max < tree_edges[i])
            max = tree_edges[i];    
    }
    cout << sum - max << '\n';
    return 0;
}