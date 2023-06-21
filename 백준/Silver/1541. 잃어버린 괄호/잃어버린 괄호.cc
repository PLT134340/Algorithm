#include <iostream>
#include <string>
#include <vector>
using namespace std;

int D[25][25] = {0};

int main() {
    string exp;
    cin >> exp;
    vector<int> oprd;
    vector<char> oprt;
    string str = "";
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] >= '0' && exp[i] <= '9')
            str += string(1, exp[i]);
        else if(exp[i] == '+' || exp[i] == '-') {
            oprt.push_back(exp[i]);
            oprd.push_back(stoi(str));
            str = "";
        }
    }
    oprd.push_back(stoi(str));

    int n = oprd.size();
    for(int i = 0; i < n; i++)
        D[i][i] = oprd[i];
    
    for(int dgnl = 1; dgnl < n; dgnl++)
        for(int i = 0; i < n - dgnl; i++) {
            int j = i + dgnl;
            int min = INT32_MAX;
            for(int k = i; k < j; k++) {
                int tmp;
                if(oprt[k] == '+')
                    tmp = D[i][k] + D[k + 1][j];
                else
                    tmp = D[i][k] - D[k + 1][j];
                if(tmp < min)
                    min = tmp;
            }
            D[i][j] = min;
        }
    cout << D[0][n - 1] << endl;
    return 0;
}