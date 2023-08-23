#include <iostream>
#include <string>
using namespace std;

class Deque {
    int arr[2000000];
    int start = 1000000;
    int end = 999999;

public:
    void push_front(int n);
    void push_back(int n);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    int front();
    int back();
};

void Deque::push_front(int n) {
    arr[--start] = n;
}

void Deque::push_back(int n) {
    arr[++end] = n;
}

int Deque::pop_front() {
    if(empty())
        return -1;
    else
        return arr[start++];
}

int Deque::pop_back() {
    if(empty())
        return -1;
    else
        return arr[end--];
}

int Deque::size() {
    return end - start + 1;
}

bool Deque::empty() {
    return start == end + 1;
}

int Deque::front() {
    if(empty())
        return -1;
    else 
        return arr[start];
}

int Deque::back() {
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

    Deque dq;
    for(int i = 0; i < n; i++) {
        int instruction;
        cin >> instruction;

        int num;
        switch(instruction) {
            case 1:
                cin >> num;
                dq.push_front(num);
                break;
            case 2:
                cin >> num;
                dq.push_back(num);
                break;
            case 3:
                cout << dq.pop_front() << '\n';
                break;
            case 4:
                cout << dq.pop_back() << '\n';
                break;
            case 5:
                cout << dq.size() << '\n';
                break;
            case 6:
                cout << dq.empty() << '\n';
                break;
            case 7:
                cout << dq.front() << '\n';
                break;          
            case 8:
                cout << dq.back() << '\n';
                break;     
        }
    }
    return 0;
}