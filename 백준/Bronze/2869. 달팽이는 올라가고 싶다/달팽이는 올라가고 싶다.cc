#include <iostream>
using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;
    
    v -= a;
    int result = v / (a - b) + 1;
    if(v % (a - b) != 0)
        result++;
    cout << result;
    return 0;
}