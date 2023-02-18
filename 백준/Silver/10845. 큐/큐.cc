#include <iostream>
#include <string>
using namespace std;

class queue
{
private:
    int arr[10000];
    int start;
    int end;

public:
    queue()
        :start(0), end(-1) {}
    void push(int n)
    {
        arr[++end] = n;
    }
    int pop()
    {
        if(empty())
            return -1;
        else
            return arr[start++];
    }
    int size()
    {
        return end - start + 1;
    }
    int empty()
    {
        if(start > end)
            return 1;
        else
            return 0;
    }
    int front()
    {
        if(empty())
            return -1;
        else
            return arr[start];
    }
    int back()
    {
        if(empty())
            return -1;
        else
            return arr[end];
    }
};

int main()
{
    int n;
    cin >> n;
    queue q;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        if(str.compare("push") == 0)
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(str.compare("pop") == 0)
            cout << q.pop() << '\n';
        else if(str.compare("size") == 0)
            cout << q.size() << '\n';
        else if(str.compare("empty") == 0)
            cout << q.empty() << '\n';
        else if(str.compare("front") == 0)
            cout << q.front() << '\n';
        else if(str.compare("back") == 0)
            cout << q.back() << '\n';
    }
    return 0;
}