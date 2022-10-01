#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int order;
    int tmp;
    for(int i = 0; i < 9; i++)
    {
        cin >> tmp;
        if(tmp > max)
        {
            max = tmp;
            order = i + 1;
        }
    }

    cout << max << '\n' << order;
    return 0;
}