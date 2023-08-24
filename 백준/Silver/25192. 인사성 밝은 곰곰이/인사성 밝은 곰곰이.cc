#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<string> s;
    int count = 0;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "ENTER") {
            count += s.size();
            s.clear();
        }
        else
            s.insert(str);   
    }
    count += s.size();

    cout << count << '\n';
    return 0;
}