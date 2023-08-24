#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    s.insert("ChongChong");
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if(s.find(a) != s.end())
            s.insert(b);
        if(s.find(b) != s.end())
            s.insert(a);
    }

    cout << s.size() << '\n';
    return 0;
}