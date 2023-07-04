#include <iostream>
using namespace std;

int arr[1000];
int length[1000] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
        
        if(length[i] == 0)
            length[i] = 1;
    }

    int max = length[0];
    for(int i = 1; i < n; i++)
        if(max < length[i])
            max = length[i];
    cout << max << '\n';
    return 0;
}