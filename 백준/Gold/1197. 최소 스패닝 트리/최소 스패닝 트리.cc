#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct edge {
    int start;
    int end;
    int weight;
};

struct compare {
    bool operator()(const edge &a, const edge &b) {
        return a.weight > b.weight;
    }
};

int prim(int v, vector<vector<edge>> &edges);

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<edge>> edges(v + 1);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(edge{a, b, c});
        edges[b].push_back(edge{b, a, c});
    }

    cout << prim(v, edges) << '\n';
    return 0;
}

int prim(int v, vector<vector<edge>> &edges) {
    set<int> visited;
    visited.insert(1);
    priority_queue<edge, vector<edge>, compare> pq;
    for (edge e : edges[1])
        pq.push(e);
    
    int result = 0;
    while(visited.size() < v) {
        auto [start, end, weight] = pq.top();
        pq.pop();
        
        if(visited.find(end) == visited.end()) {
            result += weight;
            visited.insert(end);
            for (edge e : edges[end])
                if(visited.find(e.end) == visited.end())
                    pq.push(e);
        }
    }
    return result;
}