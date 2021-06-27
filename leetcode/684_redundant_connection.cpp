class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int, vector<int>> adj;
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // for(const auto& [edge, neighbours] : adj) {
        //     cout << "edge is " << edge << endl;
        //     cout << "neighbors:";
        //     for (const int& i : neighbours) cout << " " << i;
        //     cout << endl;
        // }
        for(int i=n-1;i>=0;i--) {
            vector<bool> visited(n, false);
            if (dfs(adj, edges[i], visited) == n-1) {
                return edges[i];
            }
        }
        return {};
    }
    int dfs(map<int, vector<int>>& adj, vector<int> remove_vertex, vector<bool>& visited) {
        vector<int> path;
        for(auto vertex = adj.begin(); vertex != adj.end(); vertex++) {
            if (!visited[vertex->first]) {
                dfs_util(vertex->first, adj, remove_vertex, visited, path);
            }
        }
        // cout << "dfs for removed vertex " << remove_vertex[0] << " " << remove_vertex[1] << endl;
        // for (int& p : path) cout << p << " ";
        // cout << endl;
        return path.size();
    }
    void dfs_util(int curr_vertex, map<int, vector<int>>& adj, vector<int> remove_vertex, vector<bool>& visited, vector<int>& path) {
        visited[curr_vertex] = true;
        for (int& vertex : adj.find(curr_vertex)->second) {
            if ((curr_vertex == remove_vertex[0] && vertex == remove_vertex[1]) || (curr_vertex == remove_vertex[1] && vertex == remove_vertex[0])) continue;
            if (!visited[vertex]) {
                path.push_back(vertex);
                dfs_util(vertex, adj, remove_vertex, visited, path);
            }
        }
    }
};
