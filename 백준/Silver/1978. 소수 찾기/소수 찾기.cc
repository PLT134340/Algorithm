#include <iostream>
using namespace std;

int main()
{
    bool arr[1001] = { 1, 1 };
    for(int i = 2; i * i <= 1000; i++)
        if(arr[i] == 0)
            for(int j = 2; i * j <= 1000; j++)
                arr[j * i] = 1;
    
    int n;
    cin >> n;
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        if(arr[temp] == 0)
            result++;
    }
    
    cout << result;
    return 0;
}