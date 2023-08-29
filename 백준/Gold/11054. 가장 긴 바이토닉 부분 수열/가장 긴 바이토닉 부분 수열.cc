#include <iostream>
using namespace std;

int arr[1000];
int ascend[1000] = {0};
int descend[1000] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int val = 0;
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j] && val < ascend[j])
                val = ascend[j];
        ascend[i] = val + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        int val = 0;
        for(int j = n - 1; j > i; j--)
            if(arr[i] > arr[j] && val < descend[j])
                val = descend[j];
        descend[i] = val + 1;
    }
    
    int max = 0;
    for(int i = 0; i < n; i++) {
        int tmp = ascend[i] + descend[i] - 1;
        if(max < tmp)
            max = tmp;
    }
    cout << max << '\n';
    return 0;
}