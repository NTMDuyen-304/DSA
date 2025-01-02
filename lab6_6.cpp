/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 06 - Exercise 6
Notes or Remarks: ......
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;

    void DFS(int v, vector<int>& component)
    {
        cout<<v<<" ";
        visited[v] = true;
        component.push_back(v);
        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFS(u, component);
            }
        }
    }
    void BFS(int v)
    {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            cout << tmp << " ";
            for (int u : adjList[tmp]) {
                if(!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjList.resize(numVertices);
        visited.resize(numVertices, false);
    }

    void addEdge(int u, int v) //add egde u-v
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void findConnectedComponents_DFS()
    {
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v])
            {
                vector<int> component;
                DFS(v, component);
                cout<<'\n';
            }
        }
    }
    void findConnectedComponents_BFS()
    {
       // vector<bool>
        for (int v=0; v < numVertices; v++) {
            if(!visited[v]) {
                BFS(v);
                cout<<'\n';
            }
        }
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    //g.addEdge(5, 6);
    g.addEdge(3, 6);
    cout << "Choose 1-BFS or 2-DFS: ";
    int check;
    cin >> check;
    cout << "\nConnected Components:" << endl;
    if(check == 1) g.findConnectedComponents_BFS();
    else g.findConnectedComponents_DFS();

    return 0;
}
