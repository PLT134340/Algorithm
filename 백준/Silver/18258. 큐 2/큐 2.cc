#include <iostream>
#include <string>
using namespace std;

class Queue {
    int arr[2000000];
    int start = 0;
    int end = -1;

public:
    void push(int n);
    int pop();
    int size();
    bool empty();
    int front();
    int back();
};

void Queue::push(int n) {
    arr[++end] = n;
}

int Queue::pop() {
    if(empty())
        return -1;
    else
        return arr[start++];
}

int Queue::size() {
    return end - start + 1;
}

bool Queue::empty() {
    return start == end + 1;
}

int Queue::front() {
    if(empty())
        return -1;
    else 
        return arr[start];
}

int Queue::back() {
    if(empty())
        return -1;
    else 
        return arr[end];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    Queue q;
    for(int i = 0; i < n; i++) {
        string instruction;
        cin >> instruction;

        if(instruction == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if(instruction == "pop")
            cout << q.pop() << '\n';
        else if(instruction == "size")
            cout << q.size() << '\n';
        else if(instruction == "empty")
            cout << q.empty() << '\n';
        else if(instruction == "front")
            cout << q.front() << '\n';
        else if(instruction == "back")
            cout << q.back() << '\n';
    }
    return 0;
}