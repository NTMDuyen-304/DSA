//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 1_HW
//Notes or Remarks: ......
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Node {
public:
    string name;
    bool isDirectory;
    vector<shared_ptr<Node>> children;
    weak_ptr<Node> parent;

    Node(string name, bool isDirectory) : name(name), isDirectory(isDirectory) {}

    // Find a child node by name
    shared_ptr<Node> findChild(const string& name) {
        for (auto& child : children) {
            if (child->name == name) {
                return child;
            }
        }
        return nullptr;
    }

    // Remove a child node by name
    bool removeChild(const string& name) {
        auto it = remove_if(children.begin(), children.end(),
                            [&name](const shared_ptr<Node>& child) { return child->name == name; });
        if (it != children.end()) {
            children.erase(it, children.end());
            return true;
        }
        return false;
    }
};

class FileSystem {
private:
    shared_ptr<Node> root;
    shared_ptr<Node> current;

public:
    FileSystem() {
        root = make_shared<Node>("root", true);
        current = root;
    }

    void list() {
        if (!current->isDirectory) {
            cout << "Current node is not a directory.\n";
            return;
        }

        if (current->children.empty()) {
            cout << "Directory is empty.\n";
        } else {
            for (const auto& child : current->children) {
                cout << (child->isDirectory ? "[DIR] " : "[FILE] ") << child->name << "\n";
            }
        }
    }

    void create(const string& name, bool isDirectory) {
        if (!current->isDirectory) {
            cout << "Cannot create inside a file.\n";
            return;
        }

        if (current->findChild(name)) {
            cout << "A file or directory with this name already exists.\n";
            return;
        }

        auto newNode = make_shared<Node>(name, isDirectory);
        newNode->parent = current;
        current->children.push_back(newNode);
        cout << (isDirectory ? "Directory" : "File") << " '" << name << "' created successfully.\n";
    }

    void navigate(const string& name) {
        if (name == "..") {
            if (current->parent.expired()) {
                cout << "Already at the root directory.\n";
            } else {
                current = current->parent.lock();
                cout << "Moved to parent directory.\n";
            }
            return;
        }

        shared_ptr<Node> child = current->findChild(name);
        if (!child) {
            cout << "Directory or file not found.\n";
            return;
        }

        if (!child->isDirectory) {
            cout << "'" << name << "' is a file, not a directory.\n";
            return;
        }

        current = child;
        cout << "Moved to directory: " << name << "\n";
    }

    void remove(const string& name) {
        if (!current->isDirectory) {
            cout << "Cannot delete from a file.\n";
            return;
        }

        if (current->removeChild(name)) {
            cout << "Deleted: " << name << "\n";
        } else {
            cout << "File or directory not found.\n";
        }
    }

    void printPath() {
        vector<string> path;
        shared_ptr<Node> temp = current;

        while (temp) {
            path.push_back(temp->name);
            temp = temp->parent.lock();
        }

        reverse(path.begin(), path.end());
        for (const auto& dir : path) {
            cout << "/" << dir;
        }
        cout << "\n";
    }
};
int main() {
    FileSystem fs;

    cout << "Welcome to the Tree-Based File System!\n";

    while (true) {
        cout << "\nCommands: ls, mkdir <name>, touch <name>, cd <name>, rm <name>, pwd, exit\n";
        cout << "> ";

        string command, arg;
        cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "ls") {
            fs.list();
        } else if (command == "mkdir") {
            cin >> arg;
            fs.create(arg, true);
        } else if (command == "touch") {
            cin >> arg;
            fs.create(arg, false);
        } else if (command == "cd") {
            cin >> arg;
            fs.navigate(arg);
        } else if (command == "rm") {
            cin >> arg;
            fs.remove(arg);
        } else if (command == "pwd") {
            fs.printPath();
        } else {
            cout << "Unknown command.\n";
        }
    }

    cout << "Exiting the File System. Goodbye!\n";
    return 0;
}
