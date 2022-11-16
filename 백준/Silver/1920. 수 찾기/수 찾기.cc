#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        if(binary_search(arr, arr + n, temp))
            cout << "1" << '\n';
        else
            cout << "0" << '\n';
    }
    delete[]arr;
    return 0;
}