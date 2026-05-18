#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto x : nums)
        {
            vector<int> temp;
            while(x>0)
            {
                temp.push_back(x%10);
                x/=10;
            }
            for(int i = temp.size()-1;i>=0;i--)
            {
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};