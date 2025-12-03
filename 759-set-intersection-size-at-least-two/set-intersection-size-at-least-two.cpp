class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int x = -1, y = -1;  // last two chosen numbers
        int count = 0;

        for (auto &v : intervals) {
            int start = v[0], end = v[1];
            int cover = 0;

            if (x >= start && x <= end) cover++;
            if (y >= start && y <= end) cover++;

            if (cover == 2) continue;  // already satisfied

            if (cover == 1) {
                // choose one more number
                count++;
                x = y;
                y = end;
            } else {
                // choose two numbers
                count += 2;
                x = end - 1;
                y = end;
            }
        }
        return count;
    }
};
