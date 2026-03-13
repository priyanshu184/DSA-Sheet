class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        // Upper bound: slowest worker doing the whole mountain alone
        long long maxW = *max_element(workerTimes.begin(), workerTimes.end());
        long long high = maxW * (long long)mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        auto canReduce = [&](long long midTime) {
            long long totalHeightReduced = 0;
            for (int wTime : workerTimes) {
                // Solve: wTime * x * (x + 1) / 2 <= midTime
                // x^2 + x - (2 * midTime / wTime) <= 0
                long long x = (-1 + sqrt(1 + 8.0 * midTime / wTime)) / 2;
                totalHeightReduced += x;
                if (totalHeightReduced >= mountainHeight) return true;
            }
            return totalHeightReduced >= mountainHeight;
        };
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};