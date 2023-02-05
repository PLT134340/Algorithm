#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    
    sort(arr, arr + n);
    int sum = 0;
    deque<pair<int, int>> dq;
    int count = 0;
    int tmp;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(count == 0)
        {
            count = 1;
            tmp = arr[i];
        }
        else if(arr[i] == arr[i - 1])
            count++;
        else
        {
            if(dq.empty())
                dq.push_back(make_pair(count, tmp));
            else if(dq.back().first < count)
            {
                dq.clear();
                dq.push_back(make_pair(count, tmp));
            }
            else if(dq.back().first == count)
                dq.push_back(make_pair(count, tmp));
            
            count = 1;
            tmp = arr[i];
        }        
    }
    if(dq.empty())
        dq.push_back(make_pair(count, tmp));
    else if(dq.back().first < count)
    {
        dq.clear();
        dq.push_back(make_pair(count, tmp));
    }
    else if(dq.back().first == count)
        dq.push_back(make_pair(count, tmp));

    
    int average = (int)round((double)sum / n);
    int median = arr[n / 2];
    int mode;
    if(dq.size() == 1)
        mode = dq.front().second;
    else
        mode = dq.at(1).second;
    int range = abs(*max_element(arr, arr + n) - *min_element(arr, arr + n));
    
    cout << average << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;
    delete[]arr;
    return 0;
}