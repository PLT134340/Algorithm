#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> tmp;
        sum += tmp * tmp;
    }
    cout << sum % 10;
    return 0;
}