#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int sum = i;
        int tmp = i;
        while(tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if(sum == n)
        {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}