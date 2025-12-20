#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int count = 0;

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows - 1; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    count++;
                    break; // move to next column
                }
            }
        }
        return count;
    }
};
