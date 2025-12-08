#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // store last index of each character
        int maxLen = 0, l = 0;

        for (int r = 0; r < s.size(); r++) {
            if (lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1; // move left pointer
            }
            lastIndex[s[r]] = r; // update last seen index
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
