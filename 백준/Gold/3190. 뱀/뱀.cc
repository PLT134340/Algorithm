#include <iostream>
#include <set>
#include <list>
using namespace std;

int n;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct snake {
    pair<int, int> head;
    pair<int, int> tail;
    list<pair<int, int>> body;
    set<pair<int, int>> bodySet;
    int dir = 0;
    int count;
    
    snake() {
        pair<int, int> start = {1, 1};
        head = start;
        tail = start;
        body.push_front(start);
        bodySet.insert(start);
        count = 0;
    }
    
    void turn(char c) {
        if (c == 'L')
            dir--;
        else if (c == 'D')
            dir++;
        
        if (dir < 0)
            dir = 3;
        if (dir > 3)
            dir = 0;
    }
    
    void move(set<pair<int, int>> &apple) {
        count++;
        
        auto [y, x] = head;
        pair<int, int> newHead = {y + dy[dir], x + dx[dir]};
        
        head = newHead;
        bodySet.insert(newHead);
        body.push_front(newHead);
        // 새로운 머리 위치에 사과가 없으면 꼬리를 줄임
        if (apple.find(newHead) == apple.end()) {
            bodySet.erase(body.back());
            body.pop_back();
        } else {
            apple.erase(newHead);
        }
    }
    
    bool isEnd() {
        auto [y, x] = head;
        if (y <= 0 || x <= 0 || y > n || x > n || body.size() != bodySet.size()) {
            return true;
        }
        
        return false;
    }
};

int main() {
    int k;
    cin >> n >> k;
    
    set<pair<int, int>> apple;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        apple.insert({y, x});
    }
    
    snake s;
            
    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        
        while (!s.isEnd() && s.count < x)
            s.move(apple);
        s.turn(c);
    }
    while (!s.isEnd())
            s.move(apple);
    
    cout << s.count << '\n';
    return 0;
}