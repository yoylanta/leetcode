class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat = flattenBoard(board, n);
        return bfs(flat, n);
    }

private:
    vector<int> flattenBoard(const vector<vector<int>>& board, int n) {
        vector<int> flat(n * n + 1, -1);
        int idx = 1;
        bool leftToRight = true;

        for (int row = n - 1; row >= 0; --row) {
            if (leftToRight) {
                for (int col = 0; col < n; ++col) {
                    flat[idx++] = board[row][col];
                }
            } else {
                for (int col = n - 1; col >= 0; --col) {
                    flat[idx++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }

        return flat;
    }

    int bfs(const vector<int>& flat, int n) {
        vector<int> min_rolls(n * n + 1, -1);
        queue<int> q;
        min_rolls[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 1; i <= 6 && x + i <= n * n; ++i) {
                int next = x + i;
                int dest = flat[next] == -1 ? next : flat[next];

                if (dest == n * n)
                    return min_rolls[x] + 1;

                if (min_rolls[dest] == -1) {
                    min_rolls[dest] = min_rolls[x] + 1;
                    q.push(dest);
                }
            }
        }

        return -1;
    }
};
