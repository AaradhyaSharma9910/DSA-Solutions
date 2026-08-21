#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // Custom GCD function
    ll findGCD(ll a, ll b) {
        while (b != 0) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();
        int m = (1 << n);

        sort(coins.begin(), coins.end());

        vector<int> bit_count(m, 0);
        vector<ll> lcm(m, 0);

        ll l = k;
        ll r = 1LL * coins[0] * k + 1;

        // Calculate LCM for every subset
        for (int mask = 1; mask < m; mask++) {

            ll cur_lcm = 1;

            for (int i = 0; i < n; i++) {

                if (mask >> i & 1) {

                    ll g = findGCD(cur_lcm, (ll)coins[i]);

                    ll temp = cur_lcm / g;

                    // Avoid LCM overflow
                    if (temp <= r / coins[i]) {
                        cur_lcm = temp * coins[i];
                    }
                    else {
                        cur_lcm = r + 1;
                        break;
                    }

                    bit_count[mask]++;
                }
            }

            lcm[mask] = cur_lcm;
        }

        // Count how many numbers <= x
        // are divisible by at least one coin
        auto get = [&](ll x) -> ll {

            ll count = 0;

            for (int mask = 1; mask < m; mask++) {

                if (lcm[mask] > x) {
                    continue;
                }

                if (bit_count[mask] & 1) {
                    count += x / lcm[mask];
                }
                else {
                    count -= x / lcm[mask];
                }
            }

            return count;
        };

        // Binary search for kth smallest number
        while (l < r) {

            ll x = l + (r - l) / 2;

            if (get(x) >= k) {
                r = x;
            }
            else {
                l = x + 1;
            }
        }

        return l;
    }
};

int main() {

    int n, k;

    cin >> n >> k;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution obj;

    cout << obj.findKthSmallest(coins, k) << endl;

    return 0;
}