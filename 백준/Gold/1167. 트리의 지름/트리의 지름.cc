#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isVisited[100001];

pair<int, int> farthest(vector<vector<pair<int, int>>>& edge, int start, int v);

int main() {
    int v;
    cin >> v;

    vector<vector<pair<int, int>>> edge(v + 1);
    for(int i = 0; i < v; i++) {
        int start, end, length;
        cin >> start >> end;
        while(end != -1) {
            cin >> length;
            edge[start].push_back({end, length});
            cin >> end;
        }
    }

    auto p = farthest(edge, 1, v);
    for(int i = 1; i <= v; i++)
        isVisited[i] = false;
    p = farthest(edge, p.first, v);
    cout << p.second << '\n';
    return 0;
}

pair<int, int> farthest(vector<vector<pair<int, int>>>& edge, int start, int v) {
    stack<pair<int, int>> s;
    pair<int, int> max = {start, 0};
    s.push(max);
    isVisited[start] = true;
    while(!s.empty()) {
        auto [current, sum] = s.top();
        s.pop();

        if(sum > max.second)
            max = {current, sum};

        for(int i = 0; i < edge[current].size(); i++) {
            auto [vertex, length] = edge[current][i];
            if(!isVisited[vertex]) {
                s.push({vertex, sum + length});
                isVisited[vertex] = true;
            }
        }
    }
    return max;
}