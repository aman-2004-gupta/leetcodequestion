#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        int closedPenalty = 0;
        for (char c : customers) {
            if (c == 'Y') closedPenalty++;
        }

        int openPenalty = 0;
        int minPenalty = closedPenalty;
        int bestHour = 0;

        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'N') {
                openPenalty++;
            } else {
                closedPenalty--;
            }

            int totalPenalty = openPenalty + closedPenalty;
            if (totalPenalty < minPenalty) {
                minPenalty = totalPenalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
