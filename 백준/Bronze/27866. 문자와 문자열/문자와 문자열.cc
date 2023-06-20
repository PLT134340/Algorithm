#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    cout << str.at(n - 1) << endl;
    return 0;
}