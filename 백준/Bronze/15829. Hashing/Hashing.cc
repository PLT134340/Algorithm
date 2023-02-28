#include <iostream>
#include <string>
using namespace std;

int main()
{
    int l;
    string str;
    cin >> l >> str;

    int mod = 1234567891;
    long long result = 0;
    for(int i = 0; i < l; i++)
    {
        int alp = str.at(i) - 'a' + 1;
        long long exp = 1;
        for(int j = 0; j < i; j++)
            exp = exp * 31 % mod;
        result += alp * exp;
    }
    cout << result % mod << endl;
    return 0;
}