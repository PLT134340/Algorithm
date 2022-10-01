#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    bool isBlank = true;
    int length = str.length();
    int result = 0;
    for(int i = 0; i < length; i++)
    {
        if(isBlank == true && str.at(i) != ' ')
            isBlank = false;
        else if(isBlank == false && str.at(i) == ' ')
        {
            isBlank = true;
            result++;
        }
    }

    if(str.back() != ' ')
        result++;

    cout << result;
    return 0;
}