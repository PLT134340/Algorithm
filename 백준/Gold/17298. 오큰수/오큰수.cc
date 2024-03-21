#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> answer(n);
    stack<pair<int, int>> s; 
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        while (!s.empty() && num > s.top().second) {
            answer[s.top().first] = num;
            s.pop();
        }
            
        s.push({i, num});
    }
    
    while (!s.empty()) {
        auto [i, num] = s.top();
        s.pop();
        answer[i] = -1;
    }
    
    for (auto num : answer)
        cout << num << ' ';
    cout << '\n';
    return 0;
}