#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Structure {
    int num_files;
    set<string> files;
    vector<string> folder;
};

map<string, Structure> mp;

Structure recurs(string name);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n + m; i++) {
        string parent_name, name;
        int is_folder;
        cin >> parent_name >> name >> is_folder;
        
        if (mp.find(parent_name) == mp.end())
                mp.insert({parent_name, Structure{0, set<string>(), vector<string>()}});
        
        if (is_folder)
            mp[parent_name].folder.push_back(name);
        else {
            mp[parent_name].files.insert(name);
            mp[parent_name].num_files++;
        }
    }
    
    recurs("main");
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        string name;
        cin >> name;
        
        int idx = name.find_last_of("/");
        if (idx < name.size())
            name = name.substr(idx + 1);
        
        cout << mp[name].files.size() << ' ' << mp[name].num_files << '\n';
    }
    return 0;
}

Structure recurs(string name) {  
    for (string str : mp[name].folder) {
        Structure child = recurs(str);
        mp[name].num_files += child.num_files;
        mp[name].files.insert(child.files.begin(), child.files.end());
    }
    
    return mp[name];
}