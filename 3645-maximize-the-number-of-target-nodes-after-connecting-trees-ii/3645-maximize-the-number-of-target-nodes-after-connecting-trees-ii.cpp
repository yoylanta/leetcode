class Solution {
public:
    vector<vector<int>> buildAdj(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    pair<vector<int>, pair<int, int>> bfsParity(const vector<vector<int>>& adj, int root) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(root);
        dist[root] = 0;
        int even = 0, odd = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] % 2 == 0) ++even;
            else ++odd;
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return {dist, {even, odd}};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto adj1 = buildAdj(edges1);
        auto adj2 = buildAdj(edges2);
        auto [dist1, counts1] = bfsParity(adj1, 0);
        int evenA = counts1.first, oddA = counts1.second;
        auto [dist2, counts2] = bfsParity(adj2, 0);
        int evenB = counts2.first, oddB = counts2.second;
        int maxB = max(evenB, oddB);
        vector<int> res(adj1.size());
        for (int i = 0; i < adj1.size(); ++i) {
            res[i] = (dist1[i] % 2 == 0 ? evenA : oddA) + maxB;
        }
        return res;
    }
};
