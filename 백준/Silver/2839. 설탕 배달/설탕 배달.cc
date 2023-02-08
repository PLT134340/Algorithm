#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int thr = 0;
    int fiv = 0;
    while(3 * thr + 5 * fiv != n)
    {
        if(thr == 0 && fiv == 0)
        {
            fiv = n / 5;
            thr = (n - 5 * fiv) / 3;
        }
        else
        {
            fiv--;
            thr = (n - 5 * fiv) / 3;            
        }
    }
    
    if(fiv < 0)
        cout << -1;    
    else
        cout << thr + fiv;
    return 0;
}