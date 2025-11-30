class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;

        int rem = total % p;
        if (rem == 0) return 0; // Already divisible

        unordered_map<int, int> mp;
        mp[0] = -1; // Important base case

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - rem + p) % p;

            if (mp.count(target)) {
                ans = min(ans, i - mp[target]);
            }

            mp[prefix] = i; // store latest index for prefix remainder
        }

        return ans == nums.size() ? -1 : ans;
    }
};
