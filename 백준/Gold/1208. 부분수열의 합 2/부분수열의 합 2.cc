#include <iostream>
#include <vector>
using namespace std;

void recurs(int level, int sum, vector<int> &source, vector<int> &result);
void print(vector<int> &v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, s;
    cin >> n >> s;
    
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    vector<int> source1{v.begin(), v.begin() + n / 2};
    vector<int> result1(8000001, 0);
    recurs(0, 0, source1, result1);
    if(result1[4000000] > 0)
        result1[4000000]--;
    // print(result1);
    
    vector<int> source2{v.begin() + n / 2, v.end()};
    vector<int> result2(8000001, 0);
    recurs(0, 0, source2, result2);
    if(result2[4000000] > 0)
        result2[4000000]--;
    // print(result2);
    
    int left = -4000000;
    int right = 4000000;
    long long result = result1[s + 4000000] + result2[s + 4000000];
    while(left <= 4000000 && right >= -4000000) {
        if(left + right == s) {
            result += (long long)result1[left + 4000000] * result2[right + 4000000];
            left++;
            right--;
        }
        else if(left  + right < s)
            left++;
        else
            right--;
    }
    cout << result << '\n';
    return 0;
}

void recurs(int level, int sum, vector<int> &source, vector<int> &result) {
    if(level == source.size()) {
        result[sum + 4000000]++;
        return;
    }
    
    recurs(level + 1, sum, source, result);
    recurs(level + 1, sum + source[level], source, result);
}

void print(vector<int> &v) {
    for(int i = 0; i <= 8000000; i++)
        if(v[i] > 0)
            cout << i - 4000000 << ": " << v[i] << '\n';
    cout << '\n';
}