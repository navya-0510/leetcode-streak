class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long long left = 1, right = x;
        int ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            // Avoid overflow using long long
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;        // store possible answer
                left = mid + 1;   // try bigger
            }
            else {
                right = mid - 1;  // go smaller
            }
        }

        return ans; // floor value
    }
};