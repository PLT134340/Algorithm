#include <iostream>
#include <vector>
#include <map>
using namespace std;

int R, C, M;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct Shark {
    int y;
    int x;
    int speed;
    int direction;
    int size;
    
    Shark* move();
};

map<int, Shark*> m;
vector<vector<Shark*>> matrix;

Shark* Shark::move() {
    Shark *new_shark;
    
    if (dy[direction] != 0) {
        int quot = 0; 
        int new_y;
        if (direction == 0) {
            new_y = R - 1 - y + speed;
            while (new_y >= R) {
                new_y -= R;
                new_y++;
                quot++;
            }
        } else {
            new_y = y + speed;
            while (new_y >= R) {
                new_y -= R;
                new_y++;
                quot++;
            }
        }
        
        int new_direction;
        if (quot % 2 == 0)
            new_direction = direction;
        else
            new_direction = (direction + 1) % 2;
        
        if (new_direction == 0)
            new_y = R - 1 - new_y;
            
        new_shark = new Shark{new_y, x, speed, new_direction, size};
    } else {
        int quot = 0;
        int new_x;
        if (direction == 2) {
            new_x = x + speed;
            while (new_x >= C) {
                new_x -= C;
                new_x++;
                quot++;
            }
        } else {
            new_x = C - 1 - x + speed;
            while (new_x >= C) {
                new_x -= C;
                new_x++;
                quot++;
            }
        }
        
        int new_direction;
        if (quot % 2 == 0) 
            new_direction = direction;
        else
            new_direction = 2 + (direction + 1) % 2;
        
        if (new_direction == 3)
            new_x = C - 1 - new_x;
            
        new_shark = new Shark{y, new_x, speed, new_direction, size};
    }
    
    matrix[y][x] = nullptr;
    delete this;
    return new_shark;
};

void print_matrix(vector<vector<Shark*>> &matrix);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C >> M;
    
    matrix = vector(R, vector<Shark*>(C, nullptr));
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark *shark = new Shark{r - 1, c - 1, s, d - 1, z};
        matrix[r - 1][c - 1] = shark;
        m.insert({z, shark});
    }
    
    int result = 0;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++)
            if (matrix[j][i] != nullptr) {
                Shark *shark = matrix[j][i];
                result += shark->size;
                m.erase(shark->size);
                delete shark;
                matrix[j][i] = nullptr;
                break;
            }

        vector<vector<Shark*>> new_matrix = vector(R, vector<Shark*>(C, nullptr));
        map<int, Shark*> new_map;
        
        for (auto shark : m) {
            Shark *new_shark = shark.second->move();
            
            if (new_matrix[new_shark->y][new_shark->x] != nullptr) {
                new_map.erase(new_matrix[new_shark->y][new_shark->x]->size);
                delete new_matrix[new_shark->y][new_shark->x];
                new_matrix[new_shark->y][new_shark->x] = nullptr;
            }
            
            new_matrix[new_shark->y][new_shark->x] = new_shark;
            new_map.insert({new_shark->size, new_shark});
        }
        
        matrix = new_matrix;
        m = new_map;
    }
    
    cout << result << '\n';
    return 0;
}

void print_matrix(vector<vector<Shark*>> &matrix) {
    cout << '\n';
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) 
            if (matrix[i][j] != nullptr)
                cout << matrix[i][j]->size << ' ';
            else
                cout << "0 ";
        cout << '\n';
    }    
}