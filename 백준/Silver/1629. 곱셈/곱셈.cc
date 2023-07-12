#include <iostream>
#include <unordered_map>
using namespace std;

int divPow(unordered_map<int, int>& hm, int b, int c);

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    unordered_map<int, int> hm;
    hm.insert({0, 1 % c});
    hm.insert({1, a % c});
    cout << divPow(hm, b, c) << '\n';
    return 0;
}
int divPow(unordered_map<int, int>& hm, int b, int c) {
    if(hm.find(b) != hm.end())
        return hm[b];
    if(b == 0)
        return hm[0];
    else if(b == 1)
        return hm[1];
    else {
        hm.insert({b / 2, divPow(hm, b / 2, c)});
        hm.insert({b - b / 2, divPow(hm, b - b / 2, c)});
        return (long long)hm[b / 2] * hm[b - b / 2] % c;
    } 
}
