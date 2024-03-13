#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    int n;
    cin >> n;
    vector<long long> v1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v1[i] = v1[i - 1] + tmp;
    }
    
    int m;
    cin >> m;
    vector<long long> v2(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        v2[i] = v2[i - 1] + tmp;
    }
    
    map<long long, int> sum1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++) {
            long long sub = v1[i] - v1[j];
            if (sum1.find(sub) != sum1.end())
                sum1[sub]++;
            else
                sum1[sub] = 1;
        }
    
    map<long long, int> sum2;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < i; j++) {
            long long sub = v2[i] - v2[j];
            if (sum2.find(sub) != sum2.end())
                sum2[sub]++;
            else
                sum2[sub] = 1;
        }
    
    long long count = 0;
    auto iter_sum1 = sum1.begin();
    auto iter_sum2 = sum2.rbegin();
    while (iter_sum1 != sum1.end() && iter_sum2 != sum2.rend()) {
        // cout << "sum1: (" << iter_sum1->first << ", " << iter_sum1->second << ")\n";
        // cout << "sum2: (" << iter_sum2->first << ", " << iter_sum2->second << ")\n";
        // cout << count << '\n';
        
        if (iter_sum1->first + iter_sum2->first < t)
            iter_sum1++;
        else if (iter_sum1->first + iter_sum2->first > t)
            iter_sum2++;
        else {
            count += (long long)iter_sum1->second * iter_sum2->second;
            iter_sum1++;
            iter_sum2++;
        }
    }
    
    cout << count << '\n';
    return 0;
}