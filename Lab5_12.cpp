//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 12
//Notes or Remarks: ......
#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->value == value) return node;
        if (value < node->value)
            return search(node->left, value);
        return search(node->right, value);
    }

    TreeNode* findLCAHelper(TreeNode* node, int p, int q) {
        if (!node || node->value == p || node->value == q) return node;

        TreeNode* left = findLCAHelper(node->left, p, q);
        TreeNode* right = findLCAHelper(node->right, p, q);

        if (left && right) return node;
        return left ? left : right;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) { root = insert(root, value); }
    bool search(int value) { return search(root, value) != nullptr; }

    TreeNode* findLCA(int p, int q) {
        return findLCAHelper(root, p, q);
    }

    void printNode(TreeNode* node) {
        if (node) {
            cout << "LCA: " << node->value << endl;
        } else {
            cout << "No LCA found" << endl;
        }
    }
};

int main() {
    BinaryTree tree1;
    tree1.insert(20);
    tree1.insert(8);
    tree1.insert(22);
    tree1.insert(4);
    tree1.insert(12);
    tree1.insert(10);
    tree1.insert(14);

    int p, q;
    cout << "Enter two values to find their LCA: ";
    cin >> p >> q;
    TreeNode* lca = tree1.findLCA(p, q);
    tree1.printNode(lca);

    return 0;
}
