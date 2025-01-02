/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 06 - Exercise 7
Notes or Remarks: ......
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Lớp Graph đại diện cho một đồ thị vô hướng
class Graph {
    int Vertices; // Số lượng đỉnh
    vector<vector<int>> adj; // Danh sách kề

    // Hàm DFS để tìm cầu trong đồ thị
    void DFS(int u, int parent, vector<int>& disc, vector<int>& low, vector<pair<int, int>>& bridges, int& time) {
        disc[u] = low[u] = ++time; // Gán thời gian khám phá và thời gian thấp nhất ban đầu
        for (int v : adj[u]) { // Duyệt qua các đỉnh kề của u
            if (v == parent) continue; // Bỏ qua cạnh nối đến đỉnh cha
            if (disc[v] == -1) { // Nếu đỉnh v chưa được thăm
                DFS(v, u, disc, low, bridges, time); // Gọi đệ quy DFS cho v
                low[u] = min(low[u], low[v]); // Cập nhật giá trị low của u
                if (low[v] > disc[u]) { // Nếu low của v lớn hơn disc của u, thì (u, v) là cầu
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]); // Cập nhật giá trị low của u nếu v đã được thăm
            }
        }
    }

public:
    // Constructor để khởi tạo đồ thị với số đỉnh cho trước
    Graph(int V) : Vertices(V), adj(V) {}

    // Hàm để thêm cạnh vào đồ thị
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Hàm để tìm tất cả các cầu trong đồ thị
    vector<pair<int, int>> findBridges() {
        vector<int> disc(V, -1), low(V, -1); // Khởi tạo mảng disc và low với giá trị -1
        vector<pair<int, int>> bridges; // Danh sách để lưu các cầu
        int time = 0; // Biến thời gian ban đầu
        for (int i = 0; i < V; ++i) { // Duyệt qua tất cả các đỉnh
            if (disc[i] == -1) { // Nếu đỉnh chưa được thăm
                DFS(i, -1, disc, low, bridges, time); // Gọi DFS cho đỉnh đó
            }
        }
        return bridges; // Trả về danh sách các cầu
    }
};

int main() {
    Graph g(5); // Khởi tạo đồ thị với 5 đỉnh
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    vector<pair<int, int>> bridges = g.findBridges(); // Tìm các cầu trong đồ thị

    cout << "Bridges in the graph:\n";
    for (auto& bridge : bridges) { // In ra các cầu
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
