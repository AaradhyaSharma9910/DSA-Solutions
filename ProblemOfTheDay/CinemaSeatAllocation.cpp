#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Seats 2-5
        int left = 0b00001111;

        // Seats 4-7
        int middle = 0b00111100;

        // Seats 6-9
        int right = 0b11110000;

        unordered_map<int, int> occupied;

        // Store reserved seats using bitmask
        for (const vector<int>& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 affect family seating
            if (col >= 2 && col <= 9) {
                occupied[row] |= (1 << (col - 2));
            }
        }

        // Rows with no reserved seats in 2-9
        // can accommodate 2 families
        int ans = (n - occupied.size()) * 2;

        // Check rows which have reserved seats
        for (auto& p : occupied) {

            int mask = p.second;

            bool canLeft = ((mask & left) == 0);
            bool canMiddle = ((mask & middle) == 0);
            bool canRight = ((mask & right) == 0);

            // Both left and right groups can fit
            if (canLeft && canRight) {
                ans += 2;
            }

            // At least one group can fit
            else if (canLeft || canMiddle || canRight) {
                ans += 1;
            }
        }

        return ans;
    }
};