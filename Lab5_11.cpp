//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 11
//Notes or Remarks: ......
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
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

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    map<int, vector<int>> verticalOrderTraversal() {
        map<int, vector<int>> result; 
        if (!root) return result;

        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int hd = current.second;

            result[hd].push_back(node->value);

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        return result;
    }

    void displayVerticalOrder() {
        auto result = verticalOrderTraversal();
        cout << "Vertical Order Traversal:\n";
        for (const auto& pair : result) {
            cout << "Column " << pair.first << ": ";
            for (int value : pair.second) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(6);
    tree.insert(15);
    tree.insert(4);
    tree.insert(8);
    tree.insert(12);
    tree.insert(18);
    tree.displayVerticalOrder();

    return 0;
}
