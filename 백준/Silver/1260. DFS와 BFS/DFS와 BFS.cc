#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> graph[n + 1];
    for(int i = 0; i < m; i++)
    {
        int u, w;
        cin >> u >> w;
        graph[u].push_back(w);
        graph[w].push_back(u);
    }
    for(int i = 0; i < n + 1; i++)
        sort(graph[i].begin(), graph[i].end());

    stack<int> s;
    s.push(v);
    bool checked[n + 1] = {false};
    checked[v] = true;
    cout << v << ' ';
    while(!s.empty())
    {
        vector<int> v = graph[s.top()];
        bool isExist = false;
        for(auto it = v.begin(); it != v.end(); it++)
            if(!checked[*it])
            {
                s.push(*it);
                checked[*it] = true;
                isExist = true;
                cout << *it << ' ';
                break;
            }
        if(!isExist)
            s.pop();
    }
    cout << '\n';

    queue<int> q;
    for(int i = 0; i < n + 1; i++)
        checked[i] = false;
    q.push(v);
    checked[v] = true;
    while(!q.empty())
    {
        cout << q.front() << ' ';
        vector<int> vec = graph[q.front()];
        q.pop();
        for(auto it = vec.begin(); it != vec.end(); it++)
            if(!checked[*it])
            {
                q.push(*it);
                checked[*it] = true;
            }
    }
    cout << '\n';
    return 0;
}