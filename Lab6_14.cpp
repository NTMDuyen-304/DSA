#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

double cosineSimilarity(const vector<int>& user1, const vector<int>& user2) {
    double dotProduct = 0.0, magnitude1 = 0.0, magnitude2 = 0.0;

    for (size_t i = 0; i < user1.size(); i++) {
        dotProduct += user1[i] * user2[i];
        magnitude1 += user1[i] * user1[i];
        magnitude2 += user2[i] * user2[i];
    }

    if (magnitude1 == 0 || magnitude2 == 0) return 0.0;
    return dotProduct / (sqrt(magnitude1) * sqrt(magnitude2));
}

vector<int> recommendItems(int targetUser, const vector<vector<int>>& interactionMatrix, int topK) {
    int numUsers = interactionMatrix.size();
    int numItems = interactionMatrix[0].size();

    vector<double> similarityScores(numUsers, 0.0);

    for (int i = 0; i < numUsers; i++) {
        if (i != targetUser) {
            similarityScores[i] = cosineSimilarity(interactionMatrix[targetUser], interactionMatrix[i]);
        }
    }

    vector<double> itemScores(numItems, 0.0);
    for (int i = 0; i < numUsers; i++) {
        if (i != targetUser) {
            for (int j = 0; j < numItems; j++) {
                if (interactionMatrix[i][j] > 0) {
                    itemScores[j] += similarityScores[i];
                }
            }
        }
    }

    for (int j = 0; j < numItems; j++) {
        if (interactionMatrix[targetUser][j] > 0) {
            itemScores[j] = -1.0; 
        }
    }

    // Get top-K recommendations
    vector<int> recommendations;
    for (int k = 0; k < topK; k++) {
        double maxScore = -1.0;
        int bestItem = -1;

        for (int j = 0; j < numItems; j++) {
            if (itemScores[j] > maxScore) {
                maxScore = itemScores[j];
                bestItem = j;
            }
        }

        if (bestItem != -1) {
            recommendations.push_back(bestItem);
            itemScores[bestItem] = -1.0; 
        }
    }

    return recommendations;
}

int main() {
    vector<vector<int>> interactionMatrix = {
        {1, 0, 1, 0, 0}, // User 0
        {0, 1, 0, 1, 0}, // User 1
        {1, 1, 0, 0, 1}, // User 2
        {0, 0, 1, 1, 0}  // User 3
    };

    int targetUser = 0;
    int topK = 2;

    cout << "Generating recommendations for User " << targetUser << "...\n";
    vector<int> recommendations = recommendItems(targetUser, interactionMatrix, topK);

    cout << "Recommended items: ";
    for (int item : recommendations) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
