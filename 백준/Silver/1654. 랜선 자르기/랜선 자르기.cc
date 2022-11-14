#include <iostream>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    
    int* arr = new int[k];
    for(int i = 0; i < k; i++)
        cin >> arr[i];
    
    long long start = 1;
    long long end = INT32_MAX;
    long long mid;
    int result;
    while(start <= end)
    {
        mid = (start + end) / 2;
        int temp = 0;
        for(int i = 0; i < k; i++)
            temp += arr[i] / mid;
        
        if(temp < n)
            end = mid - 1;
        else
        {
            result = mid;
            start = mid + 1;
        }
    }
    
    cout << result;
    return 0;
}