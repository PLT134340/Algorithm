#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int result = 665;
    
    int i = 1;
    while(i <= n)
    {
        result++;
        string str = to_string(result);
        if(str.find("666") != string::npos)
            i++;
    }
    cout << result;
    return 0;
}