#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;
    int count = 1;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.top() == count) {
            s.pop();
            count++;
        }

        int order;
        cin >> order;

        if(order == count)
            count++;
        else
            s.push(order);
    }

    while(!s.empty() && s.top() == count) {
        s.pop();
        count++;
    }

    if(s.empty())
        cout << "Nice\n";
    else
        cout << "Sad\n";
    return 0;
}