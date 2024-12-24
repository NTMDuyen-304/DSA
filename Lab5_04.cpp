//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 04
//Notes or Remarks: ......

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    // Helper function for insertion
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Helper function to calculate height for diameter calculation
    int heightForDiameter(Node* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        // Get heights of left and right subtrees
        int leftHeight = heightForDiameter(node->left, diameter);
        int rightHeight = heightForDiameter(node->right, diameter);

        // Update diameter if path through this node is longer
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of this subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Helper function to visualize tree structure
    void printTreeStructure(Node* root, string prefix = "", bool isLeft = false) {
        if (root == nullptr) {
            return;
        }

        cout << prefix;
        cout << (isLeft ? "      " : "       ");
        cout << root->data << endl;

        printTreeStructure(root->left, prefix + (isLeft ? "    " : "    "), true);
        printTreeStructure(root->right, prefix + (isLeft ? "    " : "    "), false);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    int getDiameter() {
        int diameter = 0;
        heightForDiameter(root, diameter);
        return diameter;
    }

    // Function to get height of a specific node
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Function to print tree structure
    void displayTree() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        cout << "Tree structure:" << endl;
        printTreeStructure(root);
    }

    // Function to print detailed diameter path information
    void analyzeDiameter() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        int diameter = getDiameter();
        cout << "Diameter of the tree: " << diameter << endl;
        cout << "This means the longest path between any two nodes has "
             << diameter << " edges" << endl;
        cout << "Maximum number of nodes in this path: " << diameter + 1 << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Insert Value\n";
        cout << "2. Calculate Diameter\n";
        cout << "3. Display Tree\n";
        cout << "4. Analyze Diameter\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << "Value inserted successfully" << endl;
                break;

            case 2:
                cout << "Diameter of the tree: " << tree.getDiameter() << endl;
                break;

            case 3:
                tree.displayTree();
                break;

            case 4:
                tree.analyzeDiameter();
                break;

            case 5:
                cout << "Exiting program" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
