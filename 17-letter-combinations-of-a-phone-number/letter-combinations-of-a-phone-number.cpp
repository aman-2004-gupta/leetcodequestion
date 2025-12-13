#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        vector<string> map = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;
        backtrack(digits, 0, current, map, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index,
                   string& current,
                   const vector<string>& map,
                   vector<string>& result) {

        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = map[digits[index] - '0'];

        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, map, result);
            current.pop_back(); // backtrack
        }
    }
};
