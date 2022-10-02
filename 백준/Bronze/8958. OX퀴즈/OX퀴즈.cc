#include <iostream>
#include <string>
using namespace std;

int score(string str);

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        cout << score(str) << '\n';
    }
    return 0;
}

int score(string str)
{
    int result = 0;
    int repeat = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str.at(i) == 'O')
        {
            repeat++;
            result += repeat;
        }
        else
            repeat = 0;
    }

    return result;
}