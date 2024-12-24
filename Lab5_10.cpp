//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 10
//Notes or Remarks: ......

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to recursively construct the tree.
TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    // Get the current root value from postorder and decrement the postIndex
    int rootValue = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootValue);

    // Get the index of the root in the inorder traversal
    int inIndex = inMap[rootValue];

    // Build the right subtree first, then the left subtree
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
    root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);

    return root;
}

// Main function to reconstruct the binary tree
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap; // Map to store the index of each element in inorder
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1; // Start from the last element in postorder
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex, inMap);
}

// Function to print the tree (inorder traversal)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Example usage
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Reconstructed Tree Inorder Traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}
