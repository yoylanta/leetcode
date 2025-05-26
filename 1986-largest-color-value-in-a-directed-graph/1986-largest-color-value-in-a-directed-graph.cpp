class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto& e : edges){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
            }
        vector<vector<int>> dp(n, vector<int>(26,0));
        queue<int> q;

        for(int i = 0; i<n; ++i){
            if(indegree[i] == 0)
            q.push(i);
            dp[i][colors[i]-'a'] = 1;
            }
        int visited = 0;
        int result = 0;

        while(!q.empty()){
            int u = q.front(); q.pop();
            visited++;
            for (int v : graph[u]) {
                for (int c = 0; c < 26; ++c) {
                    int add = (colors[v] - 'a' == c) ? 1 : 0;
                    dp[v][c] = max(dp[v][c], dp[u][c] + add);
                    }

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
                    }
        result = max(result, *max_element(dp[u].begin(), dp[u].end()));
        }

    return visited == n ? result : -1;
    
    }
};