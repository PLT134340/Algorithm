#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000000000000LL;

struct Road {
    int from;
    int to;
    long long time;
};

struct compare {
    bool operator()(const Road &r1, const Road &r2) {
        return r1.time > r2.time;
    }
};

bool is_not_prime[10000001] = {true, true};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 2; i * i <= 10000000; i++)
        if (!is_not_prime[i])
            for (int j = 2; i * j <= 10000000; j++)
                is_not_prime[i * j] = true;
    
    vector<int> rescue_code(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> rescue_code[i];
    
    vector<vector<Road>> road(n + 1, vector<Road>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        if (is_not_prime[rescue_code[u] + rescue_code[v]])
            continue;
            

        road[u].push_back(Road{u, v, w});
        road[v].push_back(Road{v, u, w});
    }
    
    vector<bool> is_visited(n + 1, false);
    is_visited[1] = true;
    
    vector<long long> min_time(n + 1, INF);
    min_time[1] = 0;
    
    priority_queue<Road, vector<Road>, compare> pq;
    for (int i = 0; i < road[1].size(); i++)
        pq.push(road[1][i]);
        
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j < road[i].size(); j++) {
    //     auto [from, to , time] = road[i][j];
    //     cout << from << ", " << to << ", " << time << '\n';
    // }
    
    while (!pq.empty()) {
        auto [from, to , time] = pq.top();
        pq.pop();
        
        if (is_visited[to])
            continue;
        
        is_visited[to] = true;
        min_time[to] = time;
        
        for (int i = 0; i < road[to].size(); i++) {
            auto [new_from, new_to, new_time] = road[to][i];
            new_time += time;
            if (new_time < INF)
                pq.push(Road{new_from, new_to, new_time});
        }
    }
    
    if (is_visited[n])
        cout << min_time[n] << '\n';
    else
        cout << "Now where are you?\n";
    return 0;
}