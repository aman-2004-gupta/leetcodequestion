#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    bool canRun(const vector<int>& batteries, int n, ll t) {
        ll total = 0;
        for (int b : batteries)
            total += min((ll)b, t);
        return total >= t * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        ll low = 0, high = sum / n, ans = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (canRun(batteries, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
