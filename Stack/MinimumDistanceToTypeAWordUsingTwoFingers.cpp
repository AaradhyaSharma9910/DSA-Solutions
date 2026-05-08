#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[301][27][27];

    pair<int,int> getPos(char c)
    {
        int idx = c - 'A';

        return {idx / 6, idx % 6};
    }

    int dist(int a, int b)
    {
        // finger not used yet
        if(a == -1 || b == -1)
            return 0;

        pair<int,int> p1 = getPos('A' + a);
        pair<int,int> p2 = getPos('A' + b);

        int x1 = p1.first;
        int y1 = p1.second;

        int x2 = p2.first;
        int y2 = p2.second;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int l, int r)
    {
        // all characters typed
        if(i == word.size())
            return 0;

        // memoization
        if(dp[i][l + 1][r + 1] != -1)
            return dp[i][l + 1][r + 1];

        int curr = word[i] - 'A';

        // move left finger
        int useLeft =
            dist(l, curr) +
            solve(word, i + 1, curr, r);

        // move right finger
        int useRight =
            dist(r, curr) +
            solve(word, i + 1, l, curr);

        return dp[i][l + 1][r + 1] =
               min(useLeft, useRight);
    }

    int minimumDistance(string word)
    {
        memset(dp, -1, sizeof(dp));

        return solve(word, 0, -1, -1);
    }
};