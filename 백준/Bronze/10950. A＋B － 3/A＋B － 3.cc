#include <iostream>
using namespace std;

int add(int num1, int num2);

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        cout << add(num1, num2) << endl;
    }
    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}