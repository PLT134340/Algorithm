#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
    int arr[20001];
    int front;
    int back;
public:
    Deque() :front(10001), back(10000) {}
    void push_front(int n)
    {
        arr[--front] = n;
    }
    void push_back(int n)
    {
        arr[++back] = n;
    }
    int pop_front()
    {
        if(empty())
            return -1;
        return arr[front++];
    }
    int pop_back()
    {
        if(empty())
            return -1;
        return arr[back--];
    }
    int size()
    {
        return back - front + 1;
    }
    int empty()
    {
        if(size() == 0)
            return 1;
        else
            return 0;
    }
    int getFront()
    {
        if(empty())
            return -1;
        else
            return arr[front];
    }
    int getBack()
    {
        if(empty())
            return -1;
        else
            return arr[back];
    }
};

int main()
{
    int n;
    cin >> n;
    Deque dq;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        
        if(str.compare("push_front") == 0)
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(str.compare("push_back") == 0)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(str.compare("pop_front") == 0)
            cout << dq.pop_front() << '\n';
        else if(str.compare("pop_back") == 0)
            cout << dq.pop_back() << '\n';
        else if(str.compare("size") == 0)
            cout << dq.size() << '\n';
        else if(str.compare("empty") == 0)
            cout << dq.empty() << '\n';
        else if(str.compare("front") == 0)
            cout << dq.getFront() << '\n';
        else if(str.compare("back") == 0)
            cout << dq.getBack() << '\n';
    }
    return 0;
}