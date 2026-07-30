class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int presses = 1;
        while (n >= 8) {
            ans += 8 * presses;
            n -= 8;
            presses++;
        }
        ans += n * presses;
        return ans;
    }
};