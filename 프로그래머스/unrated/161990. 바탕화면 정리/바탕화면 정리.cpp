#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int height = wallpaper.size();
    int width = wallpaper[0].size();
    
    int minX = width;
    int maxX = 0;
    int minY = height;
    int maxY = 0;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            if(wallpaper[i][j] == '#') {
                if(minY > i)
                    minY = i;
                if(maxY < i + 1)
                    maxY = i + 1;
                if(minX > j)
                    minX = j;
                if(maxX < j + 1)
                    maxX = j + 1;
            }
    
    vector<int> answer;
    answer.push_back(minY);
    answer.push_back(minX);
    answer.push_back(maxY);
    answer.push_back(maxX);
    return answer;
}