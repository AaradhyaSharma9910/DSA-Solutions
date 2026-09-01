#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // id[i][j] stores the bit corresponding to a litter cell
        vector<vector<int>> id(m, vector<int>(n, 0));

        int sx = 0, sy = 0, cnt = 0;

        // Find starting position and assign bit values to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = (1 << cnt);
                    cnt++;
                }
            }
        }

        // bestEnergy[x][y][mask]
        // = maximum energy with which we have reached (x,y)
        //    after collecting litter represented by mask
        vector<vector<vector<int>>> bestEnergy(
            m,
            vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        bestEnergy[sx][sy][0] = energy;

        struct Info {
            int x;
            int y;
            int mask;
            int e;
            int steps;
        };

        queue<Info> q;

        q.push({sx, sy, 0, energy, 0});

        while (!q.empty()) {

            Info t = q.front();
            q.pop();

            // All litter collected
            if (t.mask == (1 << cnt) - 1) {
                return t.steps;
            }

            // No energy left, cannot move
            if (t.e == 0) {
                continue;
            }

            for (int i = 0; i < 4; i++) {

                int nx = t.x + dx[i];
                int ny = t.y + dy[i];

                // Outside classroom or obstacle
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n ||
                    classroom[nx][ny] == 'X') {
                    continue;
                }

                // Moving onto R resets energy
                int ne;

                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }
                else {
                    ne = t.e - 1;
                }

                // Collect litter if present
                int nmask = t.mask | id[nx][ny];

                // Only visit if this state gives us more energy
                if (ne > bestEnergy[nx][ny][nmask]) {

                    bestEnergy[nx][ny][nmask] = ne;

                    q.push({
                        nx,
                        ny,
                        nmask,
                        ne,
                        t.steps + 1
                    });
                }
            }
        }

        return -1;
    }
};

// Define static constexpr arrays outside the class
constexpr int Solution::dx[4];
constexpr int Solution::dy[4];