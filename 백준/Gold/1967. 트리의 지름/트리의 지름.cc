#include <iostream>
#include <vector>
#include <stack>
using namespace std;

pair<int, int> maxWeight(vector<vector<pair<int, int>>>& edge, int start, int n);

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edge(n + 1);
    for(int i = 1; i < n; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        edge[start].push_back({end, weight});
        edge[end].push_back({start, weight});
    }

    auto start = maxWeight(edge, 1, n);
    auto result = maxWeight(edge, start.first, n);

    cout << result.second << '\n';
    return 0;
}

pair<int, int> maxWeight(vector<vector<pair<int, int>>>& edge, int start, int n) {
    vector<bool> isVisited(n + 1, false);
    isVisited[start] = true;

    pair<int, int> result = {1, 0};
    stack<pair<int, int>> s;
    s.push({start, 0});
    while(!s.empty()) {
        auto [vertex, sum] = s.top();
        s.pop();

        if(sum > result.second) {
            result.first = vertex;
            result.second = sum;
        }

        for(int i = 0; i < edge[vertex].size(); i++) {
            auto [newVertex, weight] = edge[vertex][i];
            if(!isVisited[newVertex]) {
                s.push({newVertex, sum + weight});
                isVisited[newVertex] = true;
            } 
        }
    }
    return result;
}