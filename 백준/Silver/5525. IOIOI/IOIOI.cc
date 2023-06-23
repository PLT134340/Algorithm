#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    
    string str = "I";
    for(int i = 1; i <= n; i++)
        str += "OI";
    
    int result = 0;
    size_t idx = s.find(str);
    while(idx != string::npos) {
        result++;
        idx = s.find(str, idx + 1);
    }

    cout << result << endl;
    return 0;
}