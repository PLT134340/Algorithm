#include <iostream>
#include <string>
using namespace std;

char black[8][8] = {
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
 };
char white[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

int main()
{
    int n, m;
    cin >> n >> m;
    
    char arr[50][50];
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
            arr[i][j] = str.at(j);
    }
    
    int result = INT32_MAX;
    for(int i = 0; i <= n - 8; i++)
        for(int j = 0; j <= m - 8; j++)
        {
            int b = 0;
            int w = 0;
            for(int k = 0; k < 8; k++)
                for(int l = 0; l < 8; l++)
                {
                    if(arr[i + k][j + l] != black[k][l])
                        b++;
                    if(arr[i + k][j + l] != white[k][l])
                        w++;
                }
            int min = b < w ? b : w;
            if(min < result)
                result = min;
        }
    
    cout << result;
    return 0;
}