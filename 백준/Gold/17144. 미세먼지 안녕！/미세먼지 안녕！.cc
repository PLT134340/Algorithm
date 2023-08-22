#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> air;
vector<int> cleaner;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void spread(int r, int c);
void rotate(int r, int c);
int count(int r, int c);
void print(int r, int c);

int main() {
    int r, c, t;
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        air.push_back(vector<int>(c));
        for(int j = 0; j < c; j++)
            cin >> air[i][j];
    }
        
    for(int i = 0; i < r; i++)
        if(air[i][0] == -1)
            cleaner.push_back(i);

    for(int i = 0; i < t; i++) {
        spread(r, c);
        rotate(r, c);
    }
    
    cout << count(r, c) << '\n';
    return 0;
}

void spread(int r, int c) {
    vector<vector<int>> newAir(r, vector<int>(c));
    for(int y = 0; y < r; y++)
        for(int x = 0; x < c; x++) {
            vector<pair<int, int>> v;
            for(int i = 0; i < 4; i++) {
                int newY = y + dy[i];
                int newX = x + dx[i];
                if(newY >= 0 && newY < r && newX >= 0 && newX < c && air[newY][newX] != -1)
                    v.push_back({newY, newX});
            }

            int way = v.size();
            int spreadAmount = air[y][x] / 5;
            newAir[y][x] += air[y][x] - spreadAmount * way;
            for(int i = 0; i < way; i++) {
                auto [newY, newX] = v[i];
                newAir[newY][newX] += spreadAmount;
            }
        }
    air = newAir;
}

void rotate(int r, int c) {
    int y1 = cleaner[0];
    int y2 = cleaner[1];
    int maxY = r - 1;
    int maxX = c - 1;

    for(int newY = y1 - 1; newY > 0; newY--)
        air[newY][0] = air[newY - 1][0];
    for(int newX = 0; newX < maxX; newX++)
        air[0][newX] = air[0][newX + 1];
    for(int newY = 0; newY < y1; newY++)
        air[newY][maxX] = air[newY + 1][maxX];
    for(int newX = maxX; newX > 1; newX--)
        air[y1][newX] = air[y1][newX - 1];
    air[y1][1] = 0;

    for(int newY = y2 + 1; newY < maxY; newY++)
        air[newY][0] = air[newY + 1][0];
    for(int newX = 0; newX < maxX; newX++)
        air[maxY][newX] = air[maxY][newX + 1];
    for(int newY = maxY; newY > y2; newY--)
        air[newY][maxX] = air[newY - 1][maxX];
    for(int newX = maxX; newX > 1; newX--)
        air[y2][newX] = air[y2][newX - 1];
    air[y2][1] = 0;
}

int count(int r, int c) {
    int result = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(air[i][j] != -1)
                result += air[i][j];
    return result;
}

void print(int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << air[i][j] << ' ';
        cout << '\n';
    }
}