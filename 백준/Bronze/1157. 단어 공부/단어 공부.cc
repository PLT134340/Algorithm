#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void print(int* arr);

int main()
{
    string str;
    cin >> str;
    
    int arr[26] = {0};
    int length = str.length();
    for(int i = 0; i < length; i++)
    {
        str.at(i) = toupper(str.at(i));
        arr[str.at(i) - 'A']++;
    }
    
    int max = 0;
    bool isEqual = false;
    for(int i = 1; i < 26; i++)
    {
        if(arr[i] > arr[max])
        {
            max = i;
            isEqual = false;
        }
        else if(arr[i] != 0 && arr[i] == arr[max])
            isEqual = true;
    }

    if(isEqual)
        cout << '?';
    else
        cout << (char)('A' + max);
    return 0;
}