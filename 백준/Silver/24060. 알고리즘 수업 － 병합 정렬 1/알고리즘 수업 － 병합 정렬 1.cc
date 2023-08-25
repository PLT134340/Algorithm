#include <iostream>
using namespace std;

int arr[500000] = {0};
int tmp[500000] = {0};

int mergeSort(int start, int end, int n);
void merge(int start, int mid, int end, int n, int& result);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << mergeSort(0, n - 1, k) << '\n';
    return 0;
}

int mergeSort(int start, int end, int k) {
    static int result = -1;
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid, k);
        mergeSort(mid + 1, end,  k);
        merge(start, mid, end, k, result);
    }
    return result;
}

void merge(int start, int mid, int end, int k, int& result) {
    static int count = 0;
    int i = start;
    int j = mid + 1;
    int t = 0;

    while(i <= mid && j <= end)
        if(arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    
    while(i <= mid)
        tmp[t++] = arr[i++];
    while(j <= end)
        tmp[t++] = arr[j++];
    
    i = start;
    t = 0;
    while(i <= end) {
        count++;
        // cout << count << '\n';
        if(count == k)
            result = tmp[t];
        arr[i++] = tmp[t++];
    }
}