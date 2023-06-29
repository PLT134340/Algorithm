#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> v;
        unordered_map<string, int> hm;
        for(int j = 0; j < n; j++) {
            string name, type;
            cin >> name >> type;
            if(hm.find(type) == hm.end()) {
                hm.insert({type, v.size()});
                v.push_back(1);
            } else
                v[hm.find(type)->second]++;
        }

        int result = 1;
        for(int i = 0; i < v.size(); i++)
            result *= (v[i] + 1);
        result--;
        cout << result << '\n';
    }
    return 0;
}