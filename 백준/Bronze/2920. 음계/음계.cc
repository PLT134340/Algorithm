#include <iostream>
using namespace std;

int main()
{
    int* arr = new int[8];
    for(int i = 0; i < 8; i++)
        cin >> arr[i];

    int result;
    if(arr[0] == 1)
        result = 1;
    else if(arr[0] == 8)
        result = -1;
    else
        result = 0;
    
    for(int i = 0; i < 7; i++)
        if(abs(arr[i] - arr[i + 1]) != 1)
        {
            result = 0;
            break;
        }
    delete[]arr;

    if(result == 1)
        cout << "ascending";
    else if(result == -1)
        cout << "descending";
    else
        cout << "mixed";
    return 0;
}