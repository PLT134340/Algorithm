#include <iostream>
using namespace std;

int D[1000001];

int main() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int tmp;
        if(i % 3 == 0 || i % 2 == 0){
            if(i % 3 == 0 && i % 2 == 0)
                tmp = min(D[i / 3], D[i / 2]);
            else if(i % 3 == 0)
                tmp = D[i / 3];
            else if(i % 2 == 0)
                tmp = D[i / 2];
            D[i] = min(tmp, D[i - 1]) + 1;
        }
        else
            D[i] = D[i - 1] + 1;
    }
    cout << D[n] << endl;
    return 0;
}