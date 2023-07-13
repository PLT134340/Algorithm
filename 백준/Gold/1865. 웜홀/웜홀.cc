#include <iostream>
#include <vector>
#define inf 100000000
using namespace std;

bool bellmanFord(vector<vector<pair<int, int>>>& edge, int num);

int main() {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<vector<pair<int, int>>> edge(n + 1);
        for(int j = 0; j < m; j++) {
            int s, e, t;
            cin >> s >> e >> t;
            edge[s].push_back({e, t});
            edge[e].push_back({s, t});
        }
        for(int j = 0; j < w; j++) {
            int s, e, t;
            cin >> s >> e >> t;
            edge[s].push_back({e, -t});
        }

        if(bellmanFord(edge, n))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}

bool bellmanFord(vector<vector<pair<int, int>>>& edge, int num) {
    vector<int> result(num + 1, inf);
    int start = 1;
    result[start] = 0;

    for(int k = 1; k < num; k++)
        for(int i = 1; i <= num; i++) {
            for(int j = 0; j < edge[i].size(); j++) {
                auto [vertex, weight] = edge[i][j];
                if(result[vertex] > result[i] + weight)
                    result[vertex] = result[i] + weight;
            }
        }
    for(int i = 1; i <= num; i++) {
        for(int j = 0; j < edge[i].size(); j++) {
            auto [vertex, weight] = edge[i][j];
            if(result[vertex] > result[i] + weight)
                return true;
        }
    }
    return false;
}