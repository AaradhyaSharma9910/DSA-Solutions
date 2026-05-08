#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            // opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // stack empty → invalid
                if(st.empty()) return false;
                char top = st.top();

                // check matching
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};