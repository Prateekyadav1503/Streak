class Solution {
    int memo[100][100][101];

    bool dfs(const vector<vector<char>>& grid, int r, int c, int balance, int m, int n) {
        // Update balance for current cell
        balance += (grid[r][c] == '(' ? 1 : -1);

        // Invalid prefix condition or balance exceeding maximum possible remaining path length
        if (balance < 0 || balance > (m + n) / 2) {
            return false;
        }

        // Reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        // Return cached result if already computed
        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool hasPath = false;

        // Move Down
        if (r + 1 < m) {
            hasPath = hasPath || dfs(grid, r + 1, c, balance, m, n);
        }

        // Move Right
        if (!hasPath && c + 1 < n) {
            hasPath = hasPath || dfs(grid, r, c + 1, balance, m, n);
        }

        return memo[r][c][balance] = hasPath;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length is m + n - 1. If odd, it can never form a valid balanced string
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        // Must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(memo, -1, sizeof(memo));

        return dfs(grid, 0, 0, 0, m, n);
    }
};