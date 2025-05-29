class Solution {
public:
    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj, vector<int>& color, int& even, int& odd) {
        color[node] = depth % 2;
        if (color[node] == 0) ++even;
        else ++odd;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj, color, even, odd);
            }
        }
    }

    vector<vector<int>> buildAdj(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto adj1 = buildAdj(edges1);
        auto adj2 = buildAdj(edges2);
        int n = adj1.size(), m = adj2.size();
        
        vector<int> color1(n), color2(m);
        int evenA = 0, oddA = 0, evenB = 0, oddB = 0;
        
        dfs(0, -1, 0, adj1, color1, evenA, oddA);
        dfs(0, -1, 0, adj2, color2, evenB, oddB);
        
        int maxB = max(evenB, oddB);
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = (color1[i] == 0 ? evenA : oddA) + maxB;
        }
        return res;
    }
};
