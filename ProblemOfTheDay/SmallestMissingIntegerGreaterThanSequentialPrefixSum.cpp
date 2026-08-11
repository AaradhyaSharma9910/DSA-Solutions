#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sequentialSum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1)
            sequentialSum += nums[i];
            else 
            break;
        }
        vector<bool> hashTable(1276, false);
        for(int num : nums)
        hashTable[num] = true;
        while(hashTable[sequentialSum])
        sequentialSum++;
        return sequentialSum;
    }
};