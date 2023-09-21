#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> edges(n + 1);
    for(int i = 0; i < n - 1; i++) {
        edges[wires[i][0]].push_back(wires[i][1]);
        edges[wires[i][1]].push_back(wires[i][0]);
    }
    
    int result = INT32_MAX;
    for(int i = 0; i < n - 1; i++) {
        stack<int> s;
        s.push(wires[i][0]);
        
        set<int> s1;
        s1.insert(wires[i][0]);
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            
            for(int v : edges[top])
                if(s1.find(v) == s1.end() && v != wires[i][1]) {
                    s1.insert(v);
                    s.push(v);
                }
        }
        
        s.push(wires[i][1]);
        set<int> s2;
        s2.insert(wires[i][1]);
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            
            for(int v : edges[top])
                if(s2.find(v) == s2.end() && v != wires[i][0]) {
                    s2.insert(v);
                    s.push(v);
                }
        }
        
        int sub = s1.size() - s2.size();
        sub = sub < 0 ? -sub : sub;
        if(result > sub)
            result = sub;
    }
    
    return result;
}