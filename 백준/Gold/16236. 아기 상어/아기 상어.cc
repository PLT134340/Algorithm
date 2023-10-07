#include <iostream>
#include <queue>
using namespace std;

struct BabyShark {
    int y;
    int x;
    int size;
    int eatCount;
    
    void eat() {
        eatCount++;
        if(eatCount == size) {
            size++;
            eatCount = 0;
        }
    }
};

struct posInform {
    int count;
    int y;
    int x;  
};

struct compare {
    bool operator()(const posInform &a, const posInform &b) const {
        if(a.count == b.count && a.y == b.y)
            return a.x > b.x;
        else if(a.count == b.count)
            return a.y > b.y;
        else
            return a.count > b.count;
    }
};

int n;
int arr[20][20];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

posInform getNearestFishPos(BabyShark babyShark);

int main() {
    cin >> n;
    BabyShark babyShark;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                babyShark = BabyShark{i, j, 2, 0};
                arr[i][j] = 0;
            }
        }
    
    int result = 0;
    posInform nextPos = getNearestFishPos(babyShark);
    while(nextPos.count != -1) {
        result += nextPos.count;
        babyShark.y = nextPos.y;
        babyShark.x = nextPos.x;
        babyShark.eat();
        arr[nextPos.y][nextPos.x] = 0;
        nextPos = getNearestFishPos(babyShark);
    }
    
    cout << result << '\n';
    return 0;
}

posInform getNearestFishPos(BabyShark babyShark) {
    bool isVisited[20][20] = {false};
    isVisited[babyShark.y][babyShark.x] = true;
    
    priority_queue<posInform, vector<posInform>, compare> q; // {count, y, x}
    q.push(posInform{0, babyShark.y, babyShark.x});
    while(!q.empty()) {
        auto [count, y, x] = q.top();
        q.pop();
                
        if(arr[y][x] > 0 && arr[y][x] < babyShark.size)
            return posInform{count, y, x};
        
        for(int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(newY >= 0 && newY < n && newX >= 0 && newX < n && !isVisited[newY][newX] && arr[newY][newX] <= babyShark.size) {
                q.push(posInform{count + 1, newY, newX});
                isVisited[newY][newX] = true;
            }
        }
    }
    return posInform{-1, 0, 0};
}