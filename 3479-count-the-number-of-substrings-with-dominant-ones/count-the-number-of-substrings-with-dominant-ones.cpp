#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return number of substrings with ones >= zeros^2
    long long numberOfSubstrings(const string &s) {
        int n = (int)s.size();
        vector<int> prefZero(n+1, 0);
        for (int i = 0; i < n; ++i) prefZero[i+1] = prefZero[i] + (s[i] == '0');

        long long ans = 0;
        int maxZ = (int)(sqrt(n)) + 3; // safe upper bound for zeros

        for (int start = 0; start < n; ++start) {
            for (int z = 0; z <= maxZ; ++z) {
                int minLen = z*z + z;            // required minimum length
                int minEndByLen = start + minLen - 1;
                if (minEndByLen >= n) break;     // further z will only increase minLen

                // find first index 'firstGE' >= start such that zeros in [start..firstGE] >= z
                int lo = start, hi = n-1, firstGE = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    int zeros = prefZero[mid+1] - prefZero[start];
                    if (zeros >= z) {
                        firstGE = mid;
                        hi = mid - 1;
                    } else lo = mid + 1;
                }
                if (firstGE == -1) break; // no end index has zeros >= z, larger z impossible

                int zerosAtFirstGE = prefZero[firstGE+1] - prefZero[start];
                if (zerosAtFirstGE > z) continue; // no substring with exactly z zeros; try next z

                // find first index 'firstGT' where zeros > z (upper_bound)
                lo = firstGE; hi = n-1;
                int firstGT = n; // default none found -> firstGT = n
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    int zeros = prefZero[mid+1] - prefZero[start];
                    if (zeros > z) {
                        firstGT = mid;
                        hi = mid - 1;
                    } else lo = mid + 1;
                }
                int lastIndexWithExactlyZ = firstGT - 1;

                // earliest end index that satisfies both "length ≥ minLen" and "zeros == z"
                int earliestValidEnd = max(firstGE, minEndByLen);
                if (earliestValidEnd > lastIndexWithExactlyZ) continue; // no valid end

                // count all valid ends in [earliestValidEnd .. lastIndexWithExactlyZ]
                ans += (lastIndexWithExactlyZ - earliestValidEnd + 1);
            }
        }
        return ans;
    }
};
