#include <iostream>
#include <string>
using namespace std;

bool set[21] = {false};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if(str == "all")
            for(int j = 1; j <= 20; j++)
                set[j] = true;
        else if(str == "empty")
            for(int j = 1; j <= 20; j++)
                set[j] = false;
        else {
            int n;
            cin >> n;
            if(str == "add" && set[n] == false)
                set[n] = true;
            else if(str == "remove" && set[n] == true)
                set[n] = false;
            else if(str == "check")
                cout << set[n] << '\n';
            else if(str == "toggle")
                set[n] = !set[n];
        }
    }
    return 0;
}