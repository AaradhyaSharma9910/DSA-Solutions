#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // Step 1: connect components
        for(auto &e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        // Step 2: group indices
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        int ans = 0;

        // Step 3: process each group
        for(auto &g : groups) {
            unordered_map<int, int> freq;

            // count source
            for(int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for(int idx : g.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};