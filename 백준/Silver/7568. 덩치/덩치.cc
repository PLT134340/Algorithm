#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int weight[n];
    int height[n];
    for(int i = 0; i < n; i++)
        cin >> weight[i] >> height[i];
    
    int rank[n] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(weight[i] > weight[j] && height[i] > height[j])
                rank[j]++;
    
    for(int i = 0; i < n; i++)
        cout << rank[i] + 1 << ' ';
    cout << endl;
    return 0;
}