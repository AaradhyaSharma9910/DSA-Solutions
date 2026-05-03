//Contains Duplicate
//Skeleton code
/*
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
    }
};
//Loop add (structure build)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int num : nums) {
            
        }
        return false;
    }
};*/

// Final Code
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};