#include <iostream>
using namespace std;

int n;
int inorder[100000];
int postorder[100000];
int find_idx_inorder[100001]; // +1

void divide(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return ;

    int in_root_idx = find_idx_inorder[postorder[postEnd]];
    int left_size = in_root_idx - inStart - 1;
    cout << inorder[in_root_idx] << " ";

    divide(inStart, in_root_idx-1, postStart, postStart+left_size);
    divide(in_root_idx+1, inEnd, postStart+left_size+1, postEnd-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        find_idx_inorder[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    divide(0, n-1, 0, n-1);

    return 0;
}