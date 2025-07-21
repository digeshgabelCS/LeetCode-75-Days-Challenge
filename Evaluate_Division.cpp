#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iomanip> // for setprecision

using namespace std;

class Solution {
public:
    // Graph: variable -> (connected variable -> weight)
    unordered_map<string, unordered_map<string, double>> graph;

    // DFS helper function
    double dfs(string curr, string target, unordered_set<string>& visited, double value) {
        if (graph.find(curr) == graph.end()) return -1.0;
        if (graph[curr].find(target) != graph[curr].end()) {
            return value * graph[curr][target];
        }

        visited.insert(curr);

        for (auto& neighbor : graph[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double res = dfs(neighbor.first, target, visited, value * neighbor.second);
                if (res != -1.0) return res;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            graph[A][B] = val;
            graph[B][A] = 1.0 / val;
        }

        vector<double> results;
        for (auto& query : queries) {
            string C = query[0];
            string D = query[1];

            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
            } else if (C == D) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double res = dfs(C, D, visited, 1.0);
                results.push_back(res);
            }
        }

        return results;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    };

    vector<double> result = sol.calcEquation(equations, values, queries);

    cout << fixed << setprecision(5);
    for (double val : result) {
        cout << val << endl;
    }

    return 0;
}