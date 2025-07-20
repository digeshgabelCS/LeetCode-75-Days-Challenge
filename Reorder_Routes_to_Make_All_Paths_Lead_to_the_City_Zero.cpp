// Filename: min_reorder_to_city_zero.cpp

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Build adjacency list (undirected) and store original directions in a set
        unordered_map<int, vector<int>> graph;
        unordered_set<string> directedEdges;

        for (auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].push_back(to);  // original direction
            graph[to].push_back(from);  // reverse direction for traversal
            directedEdges.insert(to_string(from) + "->" + to_string(to));  // mark directed edge
        }

        vector<bool> visited(n, false);
        int changeCount = 0;

        dfs(0, graph, directedEdges, visited, changeCount);
        return changeCount;
    }

private:
    void dfs(int node,
             unordered_map<int, vector<int>>& graph,
             unordered_set<string>& directedEdges,
             vector<bool>& visited,
             int& changeCount) {
        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                string edge = to_string(node) + "->" + to_string(neighbor);
                if (directedEdges.count(edge)) {
                    changeCount++;
                }
                dfs(neighbor, graph, directedEdges, visited, changeCount);
            }
        }
    }
};

int main() {
    Solution solution;

    int n = 6;
    vector<vector<int>> connections = {
        {0, 1},
        {1, 3},
        {2, 3},
        {4, 0},
        {4, 5}
    };

    int result = solution.minReorder(n, connections);
    cout << "Minimum number of roads to reorder: " << result << endl;

    return 0;
}