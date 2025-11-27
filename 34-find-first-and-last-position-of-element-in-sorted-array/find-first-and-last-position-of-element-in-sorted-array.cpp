class Solution {
public:
    vector<int> searchRange(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;
        int first = -1, last = -1;

        // Find First Occurrence
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (A[mid] == tar) {
                first = mid;
                end = mid - 1;
            } else if (A[mid] < tar)
                st = mid + 1;
            else
                end = mid - 1;
        }

        // Reset and Find Last Occurrence
        st = 0, end = A.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (A[mid] == tar) {
                last = mid;
                st = mid + 1;
            } else if (A[mid] < tar)
                st = mid + 1;
            else
                end = mid - 1;
        }

        return {first, last};
    }
};
