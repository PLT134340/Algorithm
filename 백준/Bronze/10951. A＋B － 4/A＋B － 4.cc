#include <iostream>
using namespace std;

int add(int num1, int num2);

int main()
{
    int num1, num2;
    while(!(cin >> num1 >> num2).eof())
        cout << add(num1, num2) << endl;
    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}