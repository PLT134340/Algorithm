#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    
    int start = 0;
    int end = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(end < arr[i])
            end = arr[i];
    }
    
    while(start + 1 < end)
    {
        int mid = (start + end) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] > mid)
                sum += arr[i] - mid;
        
        if(sum >= m)
            start = mid;
        else
            end = mid;
    }
    
    cout << start;
    delete[]arr;
    return 0;
}