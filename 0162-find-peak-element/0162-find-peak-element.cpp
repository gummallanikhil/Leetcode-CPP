// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return 0;
//         }
//         int l =0, h = nums.size() - 1;
//         while(l < h){
//             int mid = l + (h - l) / 2;
//             if(mid == 0){
//                 if(nums[mid] > nums[mid+1]) return mid;
//                 if(nums[mid] < nums[mid + 1]){
//                     l = mid + 1;
//                 }
//             }
//             else if(mid==n -  1){
//                 if(nums[mid - 1] < nums[mid]){
//                     return mid;
//                 }
//                 if(nums[mid] < nums[mid - 1]){
//                     h = mid - 1;
//             }
//         }
//         else {
//             if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid+1]){
//                 return mid;
//             }
//             else if(nums[mid] < nums[mid - 1]){
//                 h = mid - 1;
//             }
//             else if(nums[mid] < nums[mid + 1]){
//                 l = mid + 1;
//             }
//         }
//     }
//     } 
// };
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) {
//             return 0;
//         }
//         int l = 0, h = n - 1;
//         while (l <= h) {
//             int mid = l + (h - l) / 2;
//             if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
//                 return mid;
//             } else if (mid > 0 && nums[mid - 1] > nums[mid]) {
//                 h = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return -1; 
//     }
// };
// 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1]){
                high=mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};