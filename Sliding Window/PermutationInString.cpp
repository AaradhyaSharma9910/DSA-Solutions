#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //creating two arrays
        vector<int> s1Count(26,0);
        vector<int> window(26,0);
        //filling s1 frequency
        for(char c:s1)
        s1Count[c-'a']++;
        //sliding window
        for(int i=0;i<s2.size();i++)
        {
            //add current char
        window[s2[i]-'a']++;
        //remove old char (if window size exceeds)
        if ( i >= s1.length())
        {
            window[s2[i-s1.length()]-'a']--;
        }
        //compare
        if(window==s1Count)
        return true;
    }
    return false;
}
};

        
        