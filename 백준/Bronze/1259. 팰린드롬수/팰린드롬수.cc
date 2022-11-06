#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n != 0)
    {
        string str = to_string(n);
        string rev(str.rbegin(), str.rend());
        if(!str.compare(rev))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        
        cin >> n;
    }
    return 0;
}