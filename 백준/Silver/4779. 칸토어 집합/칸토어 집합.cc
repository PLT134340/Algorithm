#include <iostream>
#include <string>
using namespace std;

string cantor[13] = {"-"};

int main() {
    int tmp = 1;
    for(int i = 1; i < 13; i++, tmp *= 3) {
        string blank = "";
        for(int j = 0; j < tmp; j++)
            blank += " ";
        cantor[i] = cantor[i - 1] + blank + cantor[i - 1];
    }

    int n;
    cin >> n;
    while(!cin.eof()) {
        cout << cantor[n] << '\n';
        cin >> n;
    }
    return 0;
}