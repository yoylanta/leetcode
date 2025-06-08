class Solution {
public:
    void dfs(int curr, int n, vector<int>& result) {
        if (curr > n) return;
        result.push_back(curr);
        dfs(curr * 10, n, result);
        if (curr % 10 != 9)
            dfs(curr + 1, n, result);
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(1, n, result);
        return result;
    }
};