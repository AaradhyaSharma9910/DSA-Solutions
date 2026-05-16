/*Approach 1: Reversed Breadth-First Search
Intuition
We use breadth-first search to find the shortest path from the end of the array, n−1, back to the starting index 0.

Preprocessing: Use the Sieve of Eratosthenes to compute the list of prime factors for all numbers in the range, stored in factors.

Mapping: Traverse the array, and whenever a number is prime, store its index in edges. These act as "transit stations" that enable long-distance jumps.

During the breadth-first search, for the current index i in the queue q, we consider three types of movements:

Adjacent movement: move to i−1 or i+1.
Jump movement: for each prime factor p of nums[i], jump to all indices j stored in edges[p].
We return the depth of the BFS once index 0 is reached.
Complexity Analysis
Let MX be the maximum value in the array, and let n be the length of the array.

Time complexity: O(MXlogMX)+O(nlogMX).

The preprocessing step takes O(MXlogMX).
The BFS traversal takes O(nlogMX), since each index and each prime factor group is processed at most once.
Space complexity: O(MXloglogMX).

This is primarily used to store the prime factor table.*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    for (int i = 2; i < MX; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (factors[a].size() == 1) {
                edges[a].push_back(i);
            }
        }
        int res = 0;
        vector<bool> seen(n, false);
        seen[n - 1] = true;
        vector<int> q = {n - 1};
        while (true) {
            vector<int> q2;
            for (int i : q) {
                if (i == 0) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }
                for (int p : factors[nums[i]]) {
                    if (edges.count(p)) {
                        for (int j : edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q = move(q2);
            res++;
        }
    }
};