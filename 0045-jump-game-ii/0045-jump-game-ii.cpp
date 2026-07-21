class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int b=0;
        int maxIdx=0;
        for(int i=0; i<nums.size()-1;i++){
            maxIdx=max(maxIdx,i+nums[i]);
            if(maxIdx>=nums.size()-1){
            ans++;
            break;
        }
        if(i==b){
            ans++;
            b=maxIdx;
        }
    }
        return ans;
    }
};