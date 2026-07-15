class Solution {
public:
    int countsubarray(vector<int>& a, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < a.size(); i++) {
            if (subarraySum + a[i] <= maxSum) {
                subarraySum += a[i];
            } else {
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int partitions = countsubarray(a, mid);

            if (partitions > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};