//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 09
//Notes or Remarks: ......

#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to find the maximum path sum for a binary tree.
int findMaxPathSum(TreeNode* node, int& maxSum) {
    if (node == nullptr) return 0;

    // Recursively calculate the maximum path sum for the left and right subtrees.
    int leftSum = max(0, findMaxPathSum(node->left, maxSum));  // Ignore negative sums.
    int rightSum = max(0, findMaxPathSum(node->right, maxSum));

    // Calculate the maximum path sum passing through the current node.
    int currentPathSum = node->val + leftSum + rightSum;

    // Update the global maximum path sum.
    maxSum = max(maxSum, currentPathSum);

    // Return the maximum path sum where the current node is the end point.
    return node->val + max(leftSum, rightSum);
}

// Function to find the maximum path sum in a binary tree.
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
}

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Find and print the maximum path sum
    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    // Free allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
