class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
       
       
    //    step 1 calaculating difference of the elements and storing in the array
        vector<int> difference;
        long long sum_diff = 0 ;
        int mx = 0;

        for(int i = 0 ; i< nums1.size() ; i++){
            int tmp = abs(nums1[i] - nums2[i]);
            difference.push_back(tmp);
            sum_diff += tmp;
            mx = max(mx,tmp);
        }



    // step 2 total no of operations to be performe
        long long k = (long long) k1+k2;
        if(sum_diff <= k) return 0;

    // step 3 calculating binary operations

        int low = 0 ;
        int high = mx;

        while(low < high){
            int mid = low + (high - low)/2;
            long long acq = 0;
            for(int d : difference){
                acq +=  max(0,d - mid);
            }

            if(acq <= k ){
                high = mid;
            }else{
                low = mid+1;
            }
        }

    // step 4 last operation of squaring

        long long ans = 0 ;
        
        for(int d : difference){
            int reduced  =  min(d , low);
            k -= max(0,d - low);
            ans += 1LL*reduced*reduced;
        }

        // return ans;
    
        for(int i = 0; i < difference.size() && k > 0; i++){
            if(difference[i] >= low && low > 0){
                 ans -= 2LL * low - 1;
                  k--;
            }
        }
        return ans;
    }
};