#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    stack<string> oprt;
    stack<string> oprd;
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] >= 'A'  && expression[i] <= 'Z') {
            if(!oprt.empty() && (oprt.top() == "*" || oprt.top() == "/")) {
                string op = oprt.top(); oprt.pop();
                string oprd1 = oprd.top(); oprd.pop();

                oprd.push(oprd1 + expression[i] + op);
            } else
                oprd.push(string(1, expression[i]));
        } else {
            if(expression[i] == ')') {
                string op = oprt.top(); oprt.pop();
                string oprd2 = oprd.top(); oprd.pop();
                string oprd1;
                if(op == "(")
                    oprd.push(oprd2);
                else {
                    oprd1 = oprd.top(); oprd.pop();
                    oprt.pop(); // '(' pop
                    oprd.push(oprd1 + oprd2 + op);
                }

                if(!oprt.empty() && (oprt.top() == "*" || oprt.top() == "/")) {
                    op = oprt.top(); oprt.pop();
                    oprd2 = oprd.top(); oprd.pop();
                    oprd1 = oprd.top(); oprd.pop();

                    oprd.push(oprd1 + oprd2 + op);
                }
            } else if(!oprt.empty() && (oprt.top() == "+" || oprt.top() == "-") && (expression[i] == '+' || expression[i] == '-')) {
                string op = oprt.top(); oprt.pop();
                string oprd2 = oprd.top(); oprd.pop();
                string oprd1 = oprd.top(); oprd.pop();
                oprd.push(oprd1 + oprd2 + op);
                oprt.push(string(1, expression[i]));
            } else
                oprt.push(string(1, expression[i]));
        }
    }

    if(oprd.size() == 1) {
        string oprd1 = oprd.top(); oprd.pop();
        cout << oprd1 << '\n';
    } else {
        string oprd1, oprd2, op;
        op = oprt.top(); oprt.pop();
        oprd2 = oprd.top(); oprd.pop();
        oprd1 = oprd.top(); oprd.pop();
        cout << oprd1 + oprd2 + op << '\n';
    }
    return 0;
}