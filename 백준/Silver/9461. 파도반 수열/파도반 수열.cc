#include <iostream>
using namespace std;

long long seq[101] = {0, 1, 1, 1, 2, 2};

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for(int j = 5; j <= n; j++)
            if(seq[j] == 0)
                seq[j] = seq[j - 1] + seq[j - 5];
        cout << seq[n] << '\n';
    }
    return 0;
}