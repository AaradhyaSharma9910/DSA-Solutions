#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<long long>& arr, int k, long long dist, int n, long long per) {
        int m = arr.size();

        vector<int> nxt(m);

        // Step 1: compute next pointers (two pointers)
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < m && arr[j] - arr[i] < dist) j++;
            nxt[i] = j;
        }

        // Step 2: try starting from first n positions
        for (int i = 0; i < n; i++) {
            int count = 1;
            int curr = i;

            while (count < k) {
                if (nxt[curr] >= i + n) break; // out of window
                curr = nxt[curr];
                count++;
            }

            if (count == k) {
                // circular check
                if (arr[i] + per - arr[curr] >= dist) return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long per = 4LL * side;
        vector<long long> arr;

        // mapping
        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) arr.push_back(x);
            else if (x == side) arr.push_back(side + y);
            else if (y == side) arr.push_back(3LL * side - x);
            else arr.push_back(4LL * side - y);
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();

        // duplicate
        vector<long long> temp = arr;
        for (auto x : temp) arr.push_back(x + per);

        long long low = 0, high = per, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPlace(arr, k, mid, n, per)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};