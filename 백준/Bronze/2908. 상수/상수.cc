#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int resultA = 0;
    int resultB = 0;
    for(int i = 0; i < 3; i++)
    {
        resultA *= 10;
        resultB *= 10;
        resultA += a % 10;
        resultB += b % 10;
        a /= 10;
        b /= 10;
    }

    if(resultA > resultB)
        cout << resultA;
    else
        cout << resultB;
    return 0;
}