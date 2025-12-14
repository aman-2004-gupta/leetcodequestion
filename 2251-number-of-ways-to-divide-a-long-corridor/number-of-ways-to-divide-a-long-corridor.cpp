class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ways = 1;
        int seats = 0;
        int plants = 0;

        // Count total seats
        for (char c : corridor) {
            if (c == 'S') seats++;
        }

        if (seats == 0 || seats % 2 != 0) return 0;

        int seatCount = 0;
        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                if (seatCount > 2 && seatCount % 2 == 1) {
                    ways = (ways * (plants + 1)) % MOD;
                    plants = 0;
                }
            } else if (seatCount >= 2 && seatCount % 2 == 0) {
                plants++;
            }
        }

        return ways;
    }
};
