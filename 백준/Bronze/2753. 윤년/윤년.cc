#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int result = 0;
    if(n % 4 == 0)
    {
        result = 1;
        if(n % 100 == 0)
            result = 0;
        if(n % 400 == 0)
            result = 1;
    }
    cout << result;
    return 0;
}