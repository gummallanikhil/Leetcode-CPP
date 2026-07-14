// class Solution {
// private:
//      bool solve(vector<int> &bloomDay, int m, int k, int ith){
//         int guldasta = 0; 
//         int fool = 0;
//         for (auto it: bloomDay){
//             if(it <= ith){
//                 fool++;
//                 if(fool == k){
//                     guldasta++;
//                     fool = 0;
//                 }
//             }
//             else {
//                 fool = 0;
//             }
//         }
//         return (guldasta >= m);
//      }
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         if ((long long)m * k > (long long)bloomDay.size()) return -1;
//         int n = bloomDay.size();
//         int l = 1, h = *max_element(bloomDay.begin(), bloomDay.end());
//         int ans = -1;
//         while(l <= h){
//             int mid = l + (h - l)/2;
//             if(solve(bloomDay, m, k, mid)){
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else{
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int K){
        int cnt=0, boq=0;
        for(int i = 0; i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
                if(cnt==K){boq++; cnt=0; }
            } else {  cnt=0; }
        } return boq>=m; }
    int minDays(vector<int>& arr, int m, int k) {
        long long total=1LL*m*k;
        if(total>arr.size()){return -1;}
        int mini=*min_element(arr.begin(),arr.end());
        int maxi=*max_element(arr.begin(),arr.end());
        int low=mini, high=maxi, result=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(arr,mid,m,k)){
                result=mid; high=mid-1;
            } else {
                low=mid+1; }
        } return result;
    }
};