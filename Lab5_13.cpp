//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 13
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
]        if (!t1) return t2;
        if (!t2) return t1;
        
        t1->value += t2->value;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    void insert(int value) { root = insert(root, value); }
    void merge(BinaryTree& other) {
        root = mergeTrees(root, other.root);
    }
    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree1, tree2;

    // Insert nodes into the first tree
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
    // Insert nodes into the second tree
    tree2.insert(1);
    tree2.insert(2);
    tree2.insert(3);

    cout << "Tree 1 (in-order traversal): ";
    tree1.printTree();
    cout << "Tree 2 (in-order traversal): ";
    tree2.printTree();

    tree1.merge(tree2);

    cout << "Merged Tree (in-order traversal): ";
    tree1.printTree();

    return 0;
}
