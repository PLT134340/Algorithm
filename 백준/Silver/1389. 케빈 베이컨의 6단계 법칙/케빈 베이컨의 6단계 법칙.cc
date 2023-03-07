#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int min = INT32_MAX;
    int result;
    for(int i = 1; i <= n; i++)
    {
        int score[n + 1] = {0};
        bool visited[n + 1] = {false};
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto it = graph[v].begin(); it != graph[v].end(); it++)
                if(!visited[*it])
                {
                    q.push(*it);
                    score[*it] = score[v] + 1;
                    visited[*it] = true;
                }
        }

        int sum = 0;
        for(int i = 1; i <= n + 1; i++)
            sum += score[i];
        if(min > sum)
        {
            min = sum;
            result = i;
        }
    }

    cout << result << '\n';
    return 0;
}