class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = (*max_element(nums.begin(), nums.end())) << 1;
        vector<bool> pairXor(mx, false);
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }
        vector<int> seen(mx, 0);
        for (int x = 0; x < mx; x++) {
            if (pairXor[x]) {
                for (int c : nums) {
                    seen[x ^ c] = 1;
                }
            }
        }
        return accumulate(seen.begin(), seen.end(), 0);
    }
};