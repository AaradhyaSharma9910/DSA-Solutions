#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int dp[3] = {0, 0, 0};
        int x[2] = {0, 0};

        for (auto it = a.rbegin(); it != a.rend(); ++it) {
            int v = *it;

            int r = max({v - dp[0],
                         v + x[0] - dp[1],
                         v + x[0] + x[1] - dp[2]});

            x[1] = x[0];
            x[0] = v;

            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = r;
        }

        string ans[] = {"Bob", "Tie", "Alice"};
        return ans[max(-1, min(dp[0], 1)) + 1];
    }
};