#include <iostream>
using namespace std;

int main()
{
    bool arr[1000001] = { 1, 1 };
    for(int i = 2; i * i <= 1000000; i++)
        if(arr[i] == 0)
            for(int j = 2; i * j <= 1000000; j++)
                arr[j * i] = 1;
    
    int m, n;
    cin >> m >> n;
    for(int i = m; i <= n; i++)
        if(arr[i] == 0)
            cout << i << '\n';
    return 0;
}