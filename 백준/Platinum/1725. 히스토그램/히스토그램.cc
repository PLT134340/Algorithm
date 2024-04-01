#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int idx;
    int height;  
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    int prev = 0;
    int result = 0;
    stack<Node> s;
    
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        
        int idx, height;
        if (prev > h) {
            while (!s.empty() && s.top().height > h) {
                idx = s.top().idx;
                height = s.top().height;
                s.pop();
                // cout << "pop " << idx << ", " << height << '\n';
                
                int mul = (i - idx) * height;
                if (result < mul)
                    result = mul;
            }
            s.push(Node{idx, h});
        } else if (prev < h) {
            s.push(Node{i, h});
            // cout << "push " << i << ", " << h << '\n';
        }
        
        prev = h;
    }
    while (!s.empty()) {
        auto [idx, height] = s.top();
        s.pop();
        
        int mul = (n - idx) * height;
            if (result < mul)
                result = mul;
    }
    
    cout << result << '\n';
    return 0;
}