#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const pair<int, double> &v1, const pair<int, double> &v2) {
        return v1.second > v2.second;
    }
};

double euclidian_distance(const pair<double, double> &v1, const pair<double, double> &v2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<double, double>> vertex(n + 1);
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        vertex[i] = {y, x};
    }
    
    vector<vector<pair<int, double>>> edge(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) {
                double distance = euclidian_distance(vertex[i], vertex[j]);
                edge[i].push_back({j, distance});
                edge[j].push_back({i, distance});
            }
            
    vector<bool> is_visited(n + 1, false);
    is_visited[1] = true;
    
    priority_queue<pair<int, double>, vector<pair<int, double>>, compare> pq;
    for (int i = 0; i < edge[1].size(); i++)
        pq.push(edge[1][i]);
    
    double sum = 0;
    while (!pq.empty()) {
        auto [vertex, weight] = pq.top();
        pq.pop();
        
        if (is_visited[vertex])
            continue;
        
        is_visited[vertex] = true;
        sum += weight;
        
        for (int i = 0; i < edge[vertex].size(); i++)
            pq.push(edge[vertex][i]);
    }
    
    cout << sum << '\n';
    return 0;
}

double euclidian_distance(const pair<double, double> &v1, const pair<double, double> &v2) {
    double y_sub = v1.first - v2.first;
    double x_sub = v1.second - v2.second;
    return sqrt(y_sub * y_sub + x_sub * x_sub);
}