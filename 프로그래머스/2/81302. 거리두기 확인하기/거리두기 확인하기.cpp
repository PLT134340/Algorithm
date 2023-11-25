#include <string>
#include <vector>

using namespace std;

int distance(pair<int, int> &p1, pair<int, int> &p2) {
    auto [y1, x1] = p1;
    auto [y2, x2] = p2;
    
    int dist = abs(y1 - y2) + abs(x1 - x2);
    return dist;
}

bool isDistancing(vector<string> &place, pair<int, int> &p1, pair<int, int> &p2) {
    int dist = distance(p1, p2);
    
    if (dist == 1)
        return false;
    else if (dist == 2) {
        auto [y1, x1] = p1;
        auto [y2, x2] = p2;
        
        if (y1 == y2) {
            if (place[y1][(x1 + x2) / 2] == 'X')
                return true;
            else 
                return false;
        } else if (x1 == x2) {
            if (place[(y1 + y2) / 2][x1] == 'X')
                return true;
            else
                return false;
        } else {
            if (place[y1][x2] == 'X' && place[y2][x1] == 'X')
                return true;
            else
                return false;
        }
        return false;
    } else
        return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto place : places) {
        vector<pair<int, int>> people;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (place[i][j] == 'P')
                    people.push_back({i, j});
        
        int size = people.size();
        bool isContinue = true;
        for (int i = 0; isContinue && i < size - 1; i++)
            for (int j = i + 1; isContinue && j < size; j++)
                if (!isDistancing(place, people[i], people[j])) {
                    answer.push_back(0);
                    isContinue = false;
                }
        
        if (isContinue)
            answer.push_back(1);
    }
    return answer;
}