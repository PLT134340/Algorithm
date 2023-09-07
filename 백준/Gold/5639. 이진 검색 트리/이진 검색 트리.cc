#include <iostream>
using namespace std;

int arr[10000] = {0};

void postorder(int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    cin >> arr[0];
    if (cin.eof())
        return 0;

    int idx = 1;
    while (!cin.eof())
        cin >> arr[idx++];

    postorder(0, idx - 1);
    return 0;
}

void postorder(int start, int end) {
    if (start >= end)
        return;
    else if (start == end - 1) {
        cout << arr[start] << '\n';
        return;
    }

    int right = start + 1;
    while (right < end && arr[start] > arr[right])
        right++;

    postorder(start + 1, right);
    postorder(right, end);
    cout << arr[start] << '\n';
}