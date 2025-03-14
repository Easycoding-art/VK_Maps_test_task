#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream file("graph.txt");
    if (!file.is_open()) {
        cerr << "Error with opening file" << endl;
        return 1;
    }
    int vertex_count, edge_count;
    file >> vertex_count >> edge_count;
    vector<vector<int>> adjacency_matrix(vertex_count);
    for (int i = 0; i < edge_count; i++) {
        int u, v;
        file >> u >> v;
        adjacency_matrix[u].push_back(v);
        adjacency_matrix[v].push_back(u);
    }
    int start_vertex;
    file >> start_vertex;
    file.close();
    vector<int> distances(vertex_count, -1);
    queue<int> q;
    distances[start_vertex] = 0;
    q.push(start_vertex);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjacency_matrix[u]) {
            if (distances[v] == -1) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < vertex_count; i++) {
        cout << distances[i] << endl;
    }
    return 0;
}