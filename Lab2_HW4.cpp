/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homework - Exercise 04
Notes or Remarks: ......
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int totalCost = 0;
        int i = 0;

        while (i < n) {
            totalCost += prices[i]; // Buy the current fruit
            int freeFruits = prices[i]; // Number of subsequent fruits we can take for free
            i += freeFruits + 1; // Move to the next fruit that we need to consider buying
        }

        return totalCost;
    }
};

int main() {
    Solution solution;

    int n; // Number of fruits
    cout << "Enter the number of fruits: ";
    cin >> n;

    vector<int> prices(n); // Vector to store prices of fruits
    cout << "Enter the prices of the fruits: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    // Call the method and output the result
    int result = solution.minimumCoins(prices);
    cout << "Minimum number of coins necessary: " << result << endl;

    return 0;
}
