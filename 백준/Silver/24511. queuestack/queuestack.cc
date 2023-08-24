#include <iostream>
#include <deque>
using namespace std;

bool isStack[100000] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> isStack[i];
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(!isStack[i])
            dq.push_back(num);
    }
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        dq.push_front(num);

        cout << dq.back() << ' ';
        dq.pop_back();
    }
    cout << '\n';
    return 0;
}