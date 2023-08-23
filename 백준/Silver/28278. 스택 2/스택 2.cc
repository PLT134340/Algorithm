#include <iostream>
using namespace std;

class Stack {
    int arr[1000000];
    int pos = -1;

public:
    void push(int n);
    int pop();
    int size();
    bool empty();
    int top();
};

void Stack::push(int n) {
    arr[++pos] = n;
}

int Stack::pop() {
    if(empty())
        return -1;
    else
        return arr[pos--];
}

int Stack::size() {
    return pos + 1;
}

bool Stack::empty() {
    return pos == -1;
}

int Stack::top() {
    if(empty())
        return -1;
    else 
        return arr[pos];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    Stack s;
    for(int i = 0; i < n; i++) {
        int instruction;
        cin >> instruction;

        int num;
        switch(instruction) {
            case 1:
                cin >> num;
                s.push(num);
                break;
            case 2:
                cout << s.pop() << '\n';
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                cout << s.empty() << '\n';
                break;
            case 5:
                cout << s.top() << '\n';
                break;          
        }
    }
    return 0;
}