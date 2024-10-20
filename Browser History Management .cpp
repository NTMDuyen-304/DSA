/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homework - Exercise 02
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

class Browser {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentUrl;

public:
    Browser() : currentUrl("") {}

    // Visit a new URL and clear the forward stack
    void visit(const string& url) {
        if (!currentUrl.empty()) {
            backStack.push(currentUrl);
        }
        currentUrl = url;
        while (!forwardStack.empty()) {
            forwardStack.pop();
        }
        cout << "Visited: " << currentUrl << endl;
    }

    // Go back to the previous URL
    string back() {
        if (backStack.empty()) {
            cout << "No previous URL to go back to." << endl;
            return currentUrl;
        }
        forwardStack.push(currentUrl);
        currentUrl = backStack.top();
        backStack.pop();
        cout << "Back to: " << currentUrl << endl;
        return currentUrl;
    }

    // Go forward to the next URL
    string forward() {
        if (forwardStack.empty()) {
            cout << "No next URL to go forward to." << endl;
            return currentUrl;
        }
        backStack.push(currentUrl);
        currentUrl = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentUrl << endl;
        return currentUrl;
    }
};

int main() {
    Browser browser;
    browser.visit("httt.uit.edu.vn");
    browser.visit("uit.edu.vn");
    browser.back(); // returns "httt.uit.edu.vn"
    browser.forward(); // returns "uit.edu.vn"
    browser.visit("daa.uit.edu.vn");
    browser.back(); // returns "uit.edu.vn"

    return 0;
}
