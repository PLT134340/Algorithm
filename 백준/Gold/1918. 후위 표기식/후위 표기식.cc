#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    stack<char> oprt;
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] >= 'A' && expression[i] <= 'Z')
            cout << expression[i];
        else if(expression[i] == '(')
            oprt.push(expression[i]);
        else if(expression[i] == ')') {
            while(oprt.top() != '(') {
                cout << oprt.top();
                oprt.pop();
            }
            oprt.pop();
        } else if(expression[i] == '*' || expression[i] == '/') {
            while(!oprt.empty() && (oprt.top() == '*' || oprt.top() == '/')) {
                cout << oprt.top();
                oprt.pop();
            }
            oprt.push(expression[i]);
        } else if(expression[i] == '+' || expression[i] == '-') {
            while(!oprt.empty() && oprt.top() != '(') {
                cout << oprt.top();
                oprt.pop();
            }
            oprt.push(expression[i]);
        }
    }
    while(!oprt.empty()) {
        cout << oprt.top();
        oprt.pop();
    }
    return 0;
}