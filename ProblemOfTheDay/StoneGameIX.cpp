#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int stone : stones) {
            int type = stone % 3;

            if (type == 0) {
                cnt0++;
            } else if (type == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }

        // If the number of stones divisible by 3 is even,
        // Alice wins if there is at least one stone of each type 1 and 2.
        if (cnt0 % 2 == 0) {
            return cnt1 > 0 && cnt2 > 0;
        }

        // If cnt0 is odd, Alice wins only when the difference
        // between type 1 and type 2 stones is greater than 2.
        return abs(cnt1 - cnt2) > 2;
    }
};