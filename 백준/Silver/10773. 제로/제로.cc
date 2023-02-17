#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k;
    cin >> k;
    stack<int> s;
    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 0)
            s.pop();
        else
            s.push(tmp);
    }
    
    int result = 0;
    while(!s.empty())
    {
        result += s.top();
        s.pop();
    }
    cout << result << endl;
    return 0;
}