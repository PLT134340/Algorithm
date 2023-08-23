#include <iostream>
using namespace std;

bool isInput[2001] = {false};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        isInput[tmp + 1000] = true;
    }

    for(int i = 0; i < 2001; i++)
        if(isInput[i])
            cout << i - 1000 << '\n';
    return 0;
}