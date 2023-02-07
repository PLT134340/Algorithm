#include <iostream>
using namespace std;

int arr[15][15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

int sum(int k, int n)
{
    if(arr[k][n] == 0)
    {
        int result = 0;
        for(int i = 1; i <= n; i++)
            result += sum(k - 1, i);
        arr[k][n] = result;
        return result;
    }
    else
        return arr[k][n];
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int k, n;
        cin >> k >> n;
        cout << sum(k, n) << endl;
    }
    return 0;
}