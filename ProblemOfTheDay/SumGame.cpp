#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        auto get = [](string s) -> pair<int, int> {
            int nn = 0, qq = 0;

            for (char ch : s) {
                if (ch == '?') {
                    ++qq;
                } else {
                    nn += (ch - '0');
                }
            }

            return {nn, qq};
        };

        auto left = get(num.substr(0, n / 2));
        auto right = get(num.substr(n / 2, n / 2));

        int n0 = left.first;
        int q0 = left.second;

        int n1 = right.first;
        int q1 = right.second;

        return ((q0 + q1) % 2 == 1) ||
               (n0 - n1 != (q1 - q0) * 9 / 2);
    }
};

int main() {
    Solution obj;

    cout << boolalpha;

    cout << obj.sumGame("5023") << endl;
    cout << obj.sumGame("25??") << endl;
    cout << obj.sumGame("?3295???") << endl;

    return 0;
}