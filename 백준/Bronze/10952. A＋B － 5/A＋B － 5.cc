#include <iostream>
using namespace std;

int add(int num1, int num2);

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    while(!(num1 == 0 && num2 == 0))
    {
        cout << add(num1, num2) << endl;
        cin >> num1 >> num2;
    }
    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}