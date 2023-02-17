#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        int h, w, n;
        cin >> h >> w >> n;
        
        int floor = n % h;
        int number = n / h;
        if(floor == 0)
            floor = h;
        else
            number += 1;
        
        if(number < 10)
            cout << floor << '0' << number << '\n';
        else
            cout << floor << number << '\n';
        
    }
    return 0;
}