#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    
    delete[]arr;
    return 0;
}