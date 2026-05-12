#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][c] = max score at (i,j) using cost c
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int val = grid[0][0];
        int cost = (val == 0 ? 0 : 1);

        if (cost <= k)
            dp[0][0][cost] = val;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {

                    if (dp[i][j][c] == -1) continue;

                    // move right
                    if (j + 1 < n) {
                        int v = grid[i][j + 1];
                        int newCost = c + (v == 0 ? 0 : 1);

                        if (newCost <= k) {
                            dp[i][j + 1][newCost] = max(
                                dp[i][j + 1][newCost],
                                dp[i][j][c] + v
                            );
                        }
                    }

                    // move down
                    if (i + 1 < m) {
                        int v = grid[i + 1][j];
                        int newCost = c + (v == 0 ? 0 : 1);

                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(
                                dp[i + 1][j][newCost],
                                dp[i][j][c] + v
                            );
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans;
    }
};