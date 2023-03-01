#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        bool arr[50][50] = {false};
        bool checked[50][50] = {false};
        for(int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            arr[y][x] = true;
        }

        int result = 0;
        for(int j = 0; j < n; j++)
            for(int l = 0; l < m; l++)
                if(arr[j][l] == true && checked[j][l] == false)
                {
                    result++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(j, l));
                    checked[j][l] = true;
                    while(!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        int y = p.first;
                        int x = p.second;
                        if(y > 0 && arr[y - 1][x] == true && checked[y - 1][x] == false)
                        {
                            q.push(make_pair(y - 1, x));
                            checked[y - 1][x] = true;
                        }
                        if(x > 0 && arr[y][x - 1] == true && checked[y][x - 1] == false)
                        {
                            q.push(make_pair(y, x - 1));
                            checked[y][x - 1] = true;
                        }
                        if(y < n - 1 && arr[y + 1][x] == true && checked[y + 1][x] == false)
                        {
                            q.push(make_pair(y + 1, x));
                            checked[y + 1][x] = true;
                        }
                        if(x < m - 1 && arr[y][x + 1] == true && checked[y][x + 1] == false)
                        {
                            q.push(make_pair(y, x + 1));
                            checked[y][x + 1] = true;
                        }
                    }
                }
        cout << result << '\n';
    }
    return 0;
}