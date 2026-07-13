class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int n=arr.size();
        int res = n+k;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(arr[mid]>mid+k){
                res=mid+k;
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return res;
    }
};

