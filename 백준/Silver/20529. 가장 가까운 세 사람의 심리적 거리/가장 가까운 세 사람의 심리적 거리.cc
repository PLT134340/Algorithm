#include <iostream>
#include <string>
#include <vector>
using namespace std;

int distance(int a, int b);

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int type[16] = {0};
        for(int j = 0; j < n; j++) {
            string str;
            cin >> str;
            
            int idx = 0;
            if(str[0] == 'E')
                idx += 8;
            if(str[1] == 'N')
                idx += 4;
            if(str[2] == 'F')
                idx += 2;
            if(str[3] == 'P')
                idx++;
            type[idx]++;
        }

        int max = type[0];
        for(int i = 1; i < 16; i++)
            if(max < type[i])
                max = type[i];

        if(max >= 3)
            cout << 0 << '\n';
        else if(max == 2) {
            int min = INT32_MAX;
            for(int i = 0; i < 15; i++)
                for(int j = i + 1; j < 16; j++)
                    if(type[i] == 2 && type[j] == 1 || type[i] == 1 && type[j] == 2 || type[i] == 2 && type[j] == 2) {
                        int sum = 2 * distance(i, j);
                        if(sum < min)
                            min = sum;
                    }

            if(min > 4)
                for(int i = 0; i < 14; i++)
                    for(int j = i + 1; j < 15; j++)
                        for(int k = j + 1; k < 16; k++) 
                            if(type[i] && type[j] && type[k]) {
                                int sum = 0;
                                sum += distance(i, j);
                                sum += distance(j, k);
                                sum += distance(k, i);
                                if(sum < min)
                                    min = sum;
                            }
            cout << min << '\n';
        } else {
            int min = INT32_MAX;
            for(int i = 0; i < 14; i++)
                for(int j = i + 1; j < 15; j++)
                    for(int k = j + 1; k < 16; k++) 
                        if(type[i] && type[j] && type[k]) {
                            int sum = 0;
                            sum += distance(i, j);
                            sum += distance(j, k);
                            sum += distance(k, i);
                            if(sum < min)
                                min = sum;
                        }
            cout << min << '\n';
        }
    }
    return 0;
}

int distance(int a, int b) {
    int result = 0;
    int aRow = a / 4;
    int aCol = a % 4;
    int bRow = b / 4;
    int bCol = b % 4;
    if(aRow < 2 && bRow >= 2 || aRow >= 2 && bRow < 2)
        result++;
    if(aCol < 2 && bCol >= 2 || aCol >= 2 && bCol < 2)
        result++;
    if(aRow % 2 ^ bRow % 2)
        result++;
    if(aCol % 2 ^ bCol % 2)
        result++;
    return result;
}