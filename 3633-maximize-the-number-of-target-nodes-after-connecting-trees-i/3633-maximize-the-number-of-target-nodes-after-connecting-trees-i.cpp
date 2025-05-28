class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        auto bfs = [](vector<vector<int>>& adj, int start, int k) {
            int count = 0;
            vector<int> dist(adj.size(), -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] > k) continue;
                count++;
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return count;
        };

        int maxB = 0;
        for (int i = 0; i < n2; ++i) {
            maxB = max(maxB, bfs(adj2, i, k - 1));
        }

        vector<int> res(n1);
        for (int i = 0; i < n1; ++i) {
            res[i] = bfs(adj1, i, k) + maxB;
        }

        return res;
    }
};
