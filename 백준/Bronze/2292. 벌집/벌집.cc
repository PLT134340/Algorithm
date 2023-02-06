#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int result = 0;
    while(n > 0)
    {
        if(result == 0)
            n--;
        else
            n -= 6 * result;
        
        result++;
    }
    
    cout << result;
    return 0;
}