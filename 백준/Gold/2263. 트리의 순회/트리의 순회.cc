#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> postorder;

void recurs(int in_start, int post_start, int size);
int find(vector<int> &v, int val, int start, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    inorder = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    
    postorder = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    
    recurs(0, 0, n);
    return 0;
}

void recurs(int in_start, int post_start, int size) {
    int mid = postorder[post_start + size - 1];
    // cout << "\nmid: " << mid << ", in_start: " << in_start << ", post_start: " << post_start << ", size: " << size << '\n';
    cout << mid << ' ';
    
    int inorder_idx = find(inorder, mid, in_start, size);
    int left_size = inorder_idx - in_start;
    int right_size = size - left_size - 1;
    
    if (inorder_idx == -1) {
        cout << "\nout of bound inorder\n";
        return;
    }
    
    if (left_size > 0)
        recurs(in_start, post_start, left_size);
    if (right_size > 0)
        recurs(inorder_idx + 1, post_start + left_size, right_size);
}
    
int find(vector<int> &v, int val, int start, int size) {
    for (int i = start; i < start + size; i++)
        if (v[i] == val)
            return i;
    return -1;
}