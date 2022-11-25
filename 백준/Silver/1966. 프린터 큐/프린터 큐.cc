#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    for(int i = 0; i < num; i++)
    {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int j = 0; j < n; j++)
        {
            int status;
            cin >> status;
            
            q.push(make_pair(status, j));
            pq.push(status);
        }
        
        int result = 0;
        while(!q.empty())
        {
            pair<int, int> p = make_pair(q.front().first, q.front().second);
            q.pop();
            
            if(pq.top() == p.first)
            {
                pq.pop();
                result++;
                
                if(p.second == m)
                {
                    cout << result << '\n';
                    break;
                }
            }
            else
                q.push(p);
        }
    }
    return 0;
}