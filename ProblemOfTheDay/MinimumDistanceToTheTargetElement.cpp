#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==target)
            {
                int dist = abs(start - i);
                minDist = min(minDist,dist);
            }
        }
        return minDist;
    }
};