#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int tmp;
    deque<int> dq;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp < x)
            dq.push_back(tmp);
    }
    
    for(auto iter = dq.begin(); iter != dq.end(); iter++)
        cout << *iter << " ";
    return 0;
}