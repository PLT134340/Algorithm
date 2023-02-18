#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    int arr[10000];
    int idx;

public:
    stack()
        :idx(-1) {}
    void push(int n)
    {
        arr[++idx] = n;
    }
    int pop()
    {
        if(idx == -1)
            return -1;
        else
            return arr[idx--];
    }
    int size()
    {
        return idx + 1;
    }
    int empty()
    {
        if(idx == -1)
            return 1;
        else
            return 0;
    }
    int top()
    {
        if(idx == -1)
            return -1;
        else
            return arr[idx];
    }
};

int main()
{
    int n;
    cin >> n;
    stack s;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        if(str.compare("push") == 0)
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(str.compare("pop") == 0)
            cout << s.pop() << '\n';
        else if(str.compare("size") == 0)
            cout << s.size() << '\n';
        else if(str.compare("empty") == 0)
            cout << s.empty() << '\n';
        else if(str.compare("top") == 0)
            cout << s.top() << '\n';
    }
    return 0;
}