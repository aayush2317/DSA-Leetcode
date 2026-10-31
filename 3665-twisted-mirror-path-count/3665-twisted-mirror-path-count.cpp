
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // At start, the robot can choose right or down
        right[0][0] = 1;
        down[0][0] = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // Starting cell
                if(i == 0 && j == 0)
                    continue;

                // Arriving from the left
                if(j > 0) {
                    if(grid[i][j-1] == 0) {
                        right[i][j] = (right[i][j-1]
                                     + down[i][j-1]) % MOD;
                    }
                    else {
                        right[i][j] = down[i][j-1];
                    }
                }

                // Arriving from above
                if(i > 0) {
                    if(grid[i-1][j] == 0) {
                        down[i][j] = (right[i-1][j]
                                    + down[i-1][j]) % MOD;
                    }
                    else {
                        down[i][j] = right[i-1][j];
                    }
                }
            }
        }

        return (right[m-1][n-1] + down[m-1][n-1]) % MOD;
    }
};
