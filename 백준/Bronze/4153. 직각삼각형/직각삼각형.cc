#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    while(true)
    {
        int sum = 0;
        int max = 0;
        for(int i = 0; i < 3; i++)
        {
            cin >> arr[i];
            sum += arr[i] * arr[i];
            if(max < arr[i])
                max = arr[i];
        }
        
        if(!(arr[0] || arr[1] || arr[2]))
            break;
    
        sum -= max * max;
        if(sum == max * max)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}