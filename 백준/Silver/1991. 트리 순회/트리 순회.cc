#include <iostream>
#include <vector>
using namespace std;

struct node {
    char c;
    node* left;
    node* right;
};

void preorder(node* n);
void inorder(node* n);
void postorder(node* n);

int main() {
    int n;
    cin >> n;
    vector<node> v;
    for(int i = 0; i < n; i++)
        v.push_back({char('A' + i), nullptr, nullptr});

    for(int i = 0; i < n; i++) {
        char mid, left, right;
        cin >> mid >> left >> right;
        if(left != '.')
            v[mid - 'A'].left = &v[left - 'A'];
        if(right != '.')
            v[mid - 'A'].right = &v[right - 'A'];
    }

    preorder(&v[0]);
    cout << '\n';
    inorder(&v[0]);
    cout << '\n';
    postorder(&v[0]);
    cout << '\n';

    return 0;
}

void preorder(node* n) {
    cout << n->c;
    if(n->left != nullptr)
        preorder(n->left);
    if(n->right != nullptr)
        preorder(n->right); 
}

void inorder(node* n) {
    if(n->left != nullptr)
        inorder(n->left);
    cout << n->c;
    if(n->right != nullptr)
        inorder(n->right);
}
void postorder(node* n) {
    if(n->left != nullptr)
        postorder(n->left);
    if(n->right != nullptr)
        postorder(n->right);
    cout << n->c;
}
