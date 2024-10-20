/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homework - Exercise 03
Notes or Remarks: ......
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> canSeePersonsCount(const vector<int>& heights) {
    int n = heights.size();
    vector<int> answer(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        int count = 0;
        while (!s.empty() && heights[i] > heights[s.top()]) {
            s.pop();
            count++;
        }
        if (!s.empty()) {
            count++;
        }
        answer[i] = count;
        s.push(i);
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the people: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<int> result = canSeePersonsCount(heights);

    // Output the result
    cout << "Output: [";
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
