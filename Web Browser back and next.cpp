/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homewwork - Exercise 02
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
private:
    vector<string> history; // Store the browsing history
    int currentIndex;       // Track the current position in the history

public:
    // Constructor to initialize with homepage URL
    BrowserHistory(string homepage) {
        history.push_back(homepage); // Initialize history with homepage
        currentIndex = 0;            // Set current index to the homepage
    }

    // Visit a new URL and clear forward history
    void visit(string url) {
        // Remove any forward history
        history.erase(history.begin() + currentIndex + 1, history.end());
        history.push_back(url); // Add the new URL to the history
        currentIndex++;         // Move to the new URL
    }

    // Move back in history by a given number of steps
    string back(int steps) {
        currentIndex = max(0, currentIndex - steps); // Move back but don't go below 0
        return history[currentIndex]; // Return the current URL
    }

    // Move forward in history by a given number of steps
    string forward(int steps) {
        currentIndex = min((int)history.size() - 1, currentIndex + steps); // Move forward but don't go beyond the last index
        return history[currentIndex]; // Return the current URL
    }
};

// Function to process commands and simulate the browser history
void processBrowserHistory() {
    vector<string> commands = {"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"};
    vector<vector<string>> args = {{"uit.edu.vn"}, {"google.com"}, {"facebook.com"}, {"youtube.com"}, {"1"}, {"1"}, {"1"}, {"linkedin.com"}, {"2"}, {"2"}, {"7"}};

    BrowserHistory* browserHistory = nullptr; // Initialize BrowserHistory pointer
    vector<string> results; // To store the results

    for (size_t i = 0; i < commands.size(); ++i) {
        string command = commands[i];

        if (command == "BrowserHistory") {
            // Create BrowserHistory instance with the homepage URL
            browserHistory = new BrowserHistory(args[i][0]);
            results.push_back("null");
        } else if (command == "visit") {
            // Visit the provided URL
            browserHistory->visit(args[i][0]);
            results.push_back("null");
        } else if (command == "back") {
            // Go back by the specified number of steps
            int steps = stoi(args[i][0]);
            results.push_back(browserHistory->back(steps));
        } else if (command == "forward") {
            // Go forward by the specified number of steps
            int steps = stoi(args[i][0]);
            results.push_back(browserHistory->forward(steps));
        }
    }

    // Output the result as an array
    cout << "[";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << "\"" << results[i] << "\"";
        if (i != results.size() - 1) cout << ", "; // Add commas between elements
    }
    cout << "]" << endl;

    delete browserHistory;  // Cleanup memory
}

int main() {
    processBrowserHistory();  // Process browser history commands
    return 0;
}
