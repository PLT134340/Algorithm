#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        
        string result = "YES";
        stack<char> s;
        for(int j = 0; j < str.length(); j++)
        {
            if(str.at(j) == '(')
                s.push('(');
            else if(s.empty() && str.at(j) == ')')
            {
                result = "NO";
                break;
            }
            else if(s.top() == '(' && str.at(j) == ')')
                s.pop();
            else
            {
                result = "NO";
                break;
            }
        }
        if(!s.empty())
            result = "NO";
        
        cout << result << '\n';
    }
    return 0;
}