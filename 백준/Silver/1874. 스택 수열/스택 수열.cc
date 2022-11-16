#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    char* result = new char[2 * n];
    stack<int> s;
    int next = 1;
    int arrIdx = 0;
    int resultIdx = 0;
    while(arrIdx < n)
    {
        if(s.empty())
        {
            s.push(next++);
            result[resultIdx++] = '+';
        }
        else if(s.top() < arr[arrIdx])
        {
            s.push(next++);
            result[resultIdx++] = '+';
        }
        else if(s.top() == arr[arrIdx])
        {
            s.pop();
            result[resultIdx++] = '-';
            arrIdx++;
        }
        else
        {
            cout << "NO";
            delete[]arr;
            delete[]result;
            return 0;
        }
    }
    
    for(int i = 0; i < 2 * n; i++)
        cout << result[i] << '\n';
        
    delete[]arr;
    delete[]result;
    return 0;
}