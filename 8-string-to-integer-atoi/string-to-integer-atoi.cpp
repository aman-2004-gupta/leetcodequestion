class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;     // use long to detect overflow
        int sign = 1;
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ')
            i++;
        
        // Step 2: Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Read digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check overflow beyond 32-bit signed range
            if (result > INT_MAX) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            i++;
        }

        return (int)(result * sign);
    }
};
