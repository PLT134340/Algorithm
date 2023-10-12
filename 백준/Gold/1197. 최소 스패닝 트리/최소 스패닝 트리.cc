#include <iostream>
#include <queue>
#include <vector>
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
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
    vector<bool> isVisited(v + 1, false);
    isVisited[1] = true;
    int visitedVertex = 1;
    
    priority_queue<edge, vector<edge>, compare> pq;
    for (edge e : edges[1])
        pq.push(e);
    
    int result = 0;
    while(visitedVertex < v) {
        auto [start, end, weight] = pq.top();
        pq.pop();
        
        if(!isVisited[end]) {
            result += weight;
            isVisited[end] = true;
            visitedVertex++;
            for (edge e : edges[end])
                if(!isVisited[e.end])
                    pq.push(e);
        }
    }
    return result;
}