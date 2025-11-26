class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0) are not palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For odd digits, drop the middle digit using reversedHalf / 10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
