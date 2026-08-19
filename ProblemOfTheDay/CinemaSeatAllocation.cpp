#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b00001111;    // seats 2,3,4,5
        int middle = 0b00111100;  // seats 4,5,6,7
        int right = 0b11110000;   // seats 6,7,8,9

        unordered_map<int, int> occupied;

        for (const vector<int>& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 matter
            if (col >= 2 && col <= 9) {
                occupied[row] |= (1 << (col - 2));
            }
        }

        // Rows with no reserved seats can fit 2 families
        int ans = (n - occupied.size()) * 2;

        // Check rows having reserved seats
        for (auto& [row, mask] : occupied) {
            if ((mask & left) == 0 || 
                (mask & middle) == 0 || 
                (mask & right) == 0) {
                ans++;
            }
        }

        return ans;
    }
};