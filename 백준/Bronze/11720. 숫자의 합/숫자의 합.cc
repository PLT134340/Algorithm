#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    int result = 0;
    for(int i = 0; i < str.length(); i++)
        result += str.at(i) - '0';
    cout << result;
    return 0;
}