// The API isBadVersion is defined for you by LeetCode.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;        // lowest version we are checking
        int high = n;       // highest version we are checking
        int ans = n;              // will store the first bad version (start assuming it's n)

        while (low <= high) {     // keep searching while the range is valid
            int mid = low + (high - low) / 2;  // middle version (avoid overflow)

            if (isBadVersion((int)mid)) {
                // mid is bad → first bad version is at mid or BEFORE mid
                ans = (int)mid;   // mid is a candidate for first bad version
                high = mid - 1;   // move search to left side [low, mid-1]
            } else {
                // mid is good → first bad version must be AFTER mid
                low = mid + 1;    // move search to right side [mid+1, high]
            }
        }

        return ans;               // final answer: smallest version that was bad
    }
};
