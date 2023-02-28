#include <iostream>
using namespace std;

int main()
{
    int n, m, b;
    cin >> n >> m >> b;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[m];

    int min = 256;
    int max = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(min > arr[i][j])
                min = arr[i][j];
            if(max < arr[i][j])
                max = arr[i][j];
        }

    int minSec = INT32_MAX;
    int maxHeight = 0;
    for(int i = min; i <= max; i++)
    {
        int sec = 0;
        int blank = 0;
        int block = b;
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                if(arr[j][k] > i)
                {
                    block += arr[j][k] - i;
                    sec += 2 * (arr[j][k] - i);
                }
                else
                {
                    blank += i - arr[j][k];
                    sec += i - arr[j][k];
                }
        
        if(blank <= block && minSec >= sec)
        {
            minSec = sec;
            if(maxHeight < i)
                maxHeight = i;
        }
    }

    cout << minSec << ' ' << maxHeight << endl;
    for(int i = 0; i < n; i++)
        delete[]arr[i];
    delete[]arr;
    return 0;
}