#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <thread>
#include <chrono>

using namespace std;

struct Product {
    string name, category, description;
    double price;
};

struct ResearchPaper {
    string title, abstractText, authors;
    vector<string> keywords;
};

struct Patient {
    int id;
    string name, dob, contact;
};

struct BSTNode {
    string url;
    time_t timestamp;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string u, time_t t) : url(u), timestamp(t), left(nullptr), right(nullptr) {}
};

vector<Product> products = {
    {"Laptop", "Electronics", "High-performance laptop", 800},
    {"Headphones", "Audio", "Noise-cancelling headphones", 50},
    {"Coffee Maker", "Appliances", "Automatic coffee maker", 100}
};

vector<ResearchPaper> researchPapers = {
    {"AI in Medicine", "Using AI for diagnostics", "John Doe", {"AI", "Medicine"}},
    {"Quantum Computing", "Basics of quantum computing", "Jane Smith", {"Quantum", "Computing"}}
};

vector<Patient> patients = {
    {1, "Alice", "1990-01-01", "1234567890"},
    {2, "Bob", "1985-05-12", "0987654321"}
};

BSTNode* webpageCache = nullptr;

void insertBST(BSTNode*& root, string url, time_t timestamp) {
    if (!root) {
        root = new BSTNode(url, timestamp);
    } else if (url < root->url) {
        insertBST(root->left, url, timestamp);
    } else {
        insertBST(root->right, url, timestamp);
    }
}

void inorderBST(BSTNode* root) {
    if (root) {
        inorderBST(root->left);
        cout << root->url << " - " << ctime(&root->timestamp);
        inorderBST(root->right);
    }
}

// Task 1: E-Commerce Search Engine
void ecommerceSearchEngine() {
    cout << "\n=== Simplified E-Commerce Search Engine ===\n";
    cout << "Enter your search query: ";
    string query;
    cin.ignore();
    getline(cin, query);

    vector<Product> results;
    for (const auto& p : products) {
        if (p.name.find(query) != string::npos || p.description.find(query) != string::npos) {
            results.push_back(p);
        }
    }

    if (results.empty()) {
        cout << "No products found matching your query.\n";
    } else {
        cout << "Search Results:\n";
        for (const auto& p : results) {
            cout << "- " << p.name << " (" << p.category << "): $" << p.price << "\n";
        }
    }
}

// Task 2: Journal/Conference Search System
void journalSearchSystem() {
    cout << "\n=== Journal/Conference Search System ===\n";
    cout << "Enter keywords to search for research papers: ";
    string query;
    cin.ignore();
    getline(cin, query);

    vector<ResearchPaper> results;
    for (const auto& rp : researchPapers) {
        for (const auto& keyword : rp.keywords) {
            if (query.find(keyword) != string::npos) {
                results.push_back(rp);
                break;
            }
        }
    }

    if (results.empty()) {
        cout << "No research papers found matching your keywords.\n";
    } else {
        cout << "Relevant Papers:\n";
        for (const auto& rp : results) {
            cout << "- " << rp.title << " by " << rp.authors << "\n";
        }
    }
}

// Task 3: Hospital Management Database Search
void hospitalManagementSystem() {
    cout << "\n=== Hospital Management Database ===\n";
    cout << "Enter patient ID to search: ";
    int id;
    cin >> id;

    auto it = find_if(patients.begin(), patients.end(), [id](const Patient& p) { return p.id == id; });
    if (it != patients.end()) {
        cout << "Patient Record Found:\n";
        cout << "Name: " << it->name << ", DOB: " << it->dob << ", Contact: " << it->contact << "\n";
    } else {
        cout << "No patient record found with ID " << id << ".\n";
    }
}

// Task 4: Webpage Caching System using BST
void webpageCachingSystem() {
    cout << "\n=== Webpage Caching System ===\n";
    cout << "Enter URL to cache: ";
    string url;
    cin >> url;
    time_t now = time(0);
    insertBST(webpageCache, url, now);

    cout << "Webpage cached successfully. Current cache:\n";
    inorderBST(webpageCache);
}
void mainMenu() {
    while (true) {
        cout << "\n=== SEARCH ENGINE & ALGORITHMS MENU ===\n";
        cout << "1. Simplified E-Commerce Search Engine\n";
        cout << "2. Journal/Conference Search System\n";
        cout << "3. Hospital Management Database Search\n";
        cout << "4. Webpage Caching System using BST\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: ecommerceSearchEngine(); 
                    break;
            case 2: journalSearchSystem(); 
                    break;
            case 3: hospitalManagementSystem(); 
                    break;
            case 4: webpageCachingSystem(); 
                    break;
            case 0: cout << "Exiting the program. Goodbye!\n"; 
                    return;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
