#include <iostream>
#include <string>
using namespace std;

string PrintNewStr(int n, string str);

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int r;
        string str;
        cin >> r >> str;
        cout << PrintNewStr(r, str) << '\n';
    }
    return 0;
}

string PrintNewStr(int n, string str)
{
    string result = "";
    for(int i = 0; i < str.length(); i++)
        result.append(n, str.at(i));
    return result;
}