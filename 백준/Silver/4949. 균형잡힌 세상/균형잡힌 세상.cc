#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    while(str != ".")
    {
        stack<char> s;
        bool result = true;
        for(int i = 0; i < str.length(); i++)
        {
            if(str.at(i) == '(')
                s.push('(');
            else if(str.at(i) == '[')
                s.push('[');
            else if(str.at(i) == ')')
            {
                if(s.empty())
                    result = false;
                else if(s.top() == '(')
                    s.pop();
                else
                    result = false;
            }
            else if(str.at(i) == ']')
            {
                if(s.empty())
                    result = false;
                else if(s.top() == '[')
                    s.pop();
                else
                    result = false;
            }   
        }
        if(!s.empty())
            result = false;
        
        if(result)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
        
        getline(cin, str);
    }
    return 0;
}