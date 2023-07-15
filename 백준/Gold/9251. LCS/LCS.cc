#include <iostream>
#include <string>
using namespace std;

int lcs[1001][1001];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0; i <= str1.size(); i++)
        for(int j = 0; j <= str2.size(); j++)
            if(i == 0 || j == 0)
                lcs[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
    cout << lcs[str1.size()][str2.size()] << '\n';
    return 0;
}