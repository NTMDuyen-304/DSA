/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homwwork - Exercise 03
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive; // Duration for which tokens are valid
    unordered_map<string, int> tokens; // Token ID mapped to expiration time

public:
    // Constructor to initialize the authentication manager
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive; // Set timeToLive
    }

    // Generate a new token with the specified tokenId at currentTime
    void generate(string tokenId, int currentTime) {
        // Set the expiration time for the token
        tokens[tokenId] = currentTime + timeToLive; 
    }

    // Renew an unexpired token with the specified tokenId at currentTime
    void renew(string tokenId, int currentTime) {
        // Check if the token exists and is unexpired
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive; // Renew token by resetting its expiration time
        }
    }

    // Count the number of unexpired tokens at currentTime
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        // Iterate through the token map to count unexpired tokens
        for (auto& token : tokens) {
            if (token.second > currentTime) { // Check if the token is still valid
                count++;
            }
        }
        return count; // Return the count of valid tokens
    }
};

// Function to process commands and simulate the authentication manager
void processAuthenticationManager() {
    vector<string> commands = {
        "AuthenticationManager", "renew", "generate", "countUnexpiredTokens",
        "generate", "renew", "renew", "countUnexpiredTokens"
    };
    
    vector<vector<string>> args = {
        {"5"}, {"aaa", "1"}, {"aaa", "2"}, {"6"}, 
        {"bbb", "7"}, {"aaa", "8"}, {"bbb", "10"}, {"15"}
    };

    AuthenticationManager* authManager = nullptr; // Pointer to AuthenticationManager
    vector<string> results; // To store results

    for (size_t i = 0; i < commands.size(); ++i) {
        string command = commands[i];

        if (command == "AuthenticationManager") {
            // Create AuthenticationManager instance with timeToLive
            authManager = new AuthenticationManager(stoi(args[i][0]));
            results.push_back("null");
        } else if (command == "generate") {
            // Generate the token with the provided tokenId
            authManager->generate(args[i][0], stoi(args[i][1]));
            results.push_back("null");
        } else if (command == "renew") {
            // Renew the token with the specified tokenId
            authManager->renew(args[i][0], stoi(args[i][1]));
            results.push_back("null");
        } else if (command == "countUnexpiredTokens") {
            // Count unexpired tokens at the specified currentTime
            results.push_back(to_string(authManager->countUnexpiredTokens(stoi(args[i][0]))));
        }
    }

    // Output the results
    cout << "[";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i != results.size() - 1) cout << ", "; // Add commas between results
    }
    cout << "]" << endl;

    delete authManager; // Cleanup memory
}

int main() {
    processAuthenticationManager(); // Process authentication manager commands
    return 0;
}
