#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left != nullptr) {
                TreeNode* prev = cur->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

// Helper to print flattened tree (like a linked list)
void printRightList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Simple tree builder (example: root = new TreeNode(1, new TreeNode(2), new TreeNode(5)) needs overloads or manual linking)
int main() {
    // Example tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    // Print the flattened tree
    printRightList(root);  // Output: 1 2 3 4 5 6

    return 0;
}
