#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int m, n;
    if(a > b)
    {
        m = a;
        n = b;
    }
    else
    {
        m = b;
        n = a;
    }
    
    while(n != 0)
    {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    
    cout << m << endl;
    cout << a / m * b << endl;
    return 0;
}