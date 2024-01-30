#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
int cons, vowel;
vector<char> v;
vector<char> result;

void recurs(int level, int length);
bool isVowel(char ch);
void printResult();

int main() {
    cin >> l >> c;
    result = vector<char>(l);
    v = vector<char>(c);
    
    for (int i = 0; i < c; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), less<>());
    
    recurs(0, 0);
    return 0;
}

void recurs(int level, int length) {
    if (length == l && cons >= 2 && vowel >= 1) {
        printResult();
        return;
    } else if (length == l || level == c)
        return;
    
    bool is_vowel = isVowel(v[level]);
    
    if (is_vowel)
        vowel++;
    else
        cons++;
    result[length] = v[level];
    recurs(level + 1, length + 1);
    if (is_vowel)
        vowel--;
    else
        cons--;
        
    recurs(level + 1, length);
}

bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
}

void printResult() {
    for (char ch : result)
        cout << ch;
    cout << '\n';
}
