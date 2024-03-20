#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct Vertex {
    int num;
    int x;
    int y;
    int z;
};

struct Edge {
    int to;
    int cost;
};

struct compare {
    bool operator()(const Edge &e1, const Edge &e2) {
        return e1.cost > e2.cost;
    }
};

int manhattan_distance(const Vertex &v1, const Vertex &v2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Vertex> vertex;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vertex.push_back(Vertex{i, x, y, z});
    }
    
    vector<vector<Edge>> edge(n);
    sort(vertex.begin(), vertex.end(), [](Vertex &v1, Vertex &v2) -> bool{ return v1.x < v2.x; });
    for (int i = 1; i < n; i++) {
        int prev_num = vertex[i - 1].num;
        int num = vertex[i].num;
        int cost = manhattan_distance(vertex[i - 1], vertex[i]);
        
        edge[prev_num].push_back(Edge{num, cost});
        edge[num].push_back(Edge{prev_num, cost});
    }
    
    sort(vertex.begin(), vertex.end(), [](Vertex &v1, Vertex &v2) -> bool{ return v1.y < v2.y; });
    for (int i = 1; i < n; i++) {
        int prev_num = vertex[i - 1].num;
        int num = vertex[i].num;
        int cost = manhattan_distance(vertex[i - 1], vertex[i]);
        
        edge[prev_num].push_back(Edge{num, cost});
        edge[num].push_back(Edge{prev_num, cost});
    }
    
    sort(vertex.begin(), vertex.end(), [](Vertex &v1, Vertex &v2) -> bool{ return v1.z < v2.z; });
    for (int i = 1; i < n; i++) {
        int prev_num = vertex[i - 1].num;
        int num = vertex[i].num;
        int cost = manhattan_distance(vertex[i - 1], vertex[i]);
        
        edge[prev_num].push_back(Edge{num, cost});
        edge[num].push_back(Edge{prev_num, cost});
    }
    
    vector<bool> is_visited(n, false);
    is_visited[0] = true;
    
    priority_queue<Edge, vector<Edge>, compare> pq;
    for (int i = 0; i < edge[0].size(); i++)
        pq.push(edge[0][i]);
    
    long long result = 0;
    while (!pq.empty()) {
        auto [to, cost] = pq.top();
        pq.pop();
        
        if (is_visited[to])
            continue;
        
        is_visited[to] = true;
        result += cost;
        
        for (int i = 0; i < edge[to].size(); i++)
            pq.push(edge[to][i]);
    }
    
    cout << result << '\n';
    return 0;
}

int manhattan_distance(const Vertex &v1, const Vertex &v2) {
    return min({abs(v1.x - v2.x), abs(v1.y - v2.y), abs(v1.z - v2.z)});
}