class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin() , nums.end(), 0) - nums.begin();
        int ans = INT_MAX;


// checks in front direction of the array
        bool forward = true;
        for(int i = 1 ; i< n ; i++){
            int prev = (zero +(i-1)+n)%n;
            int curr = (zero + i+n)%n;

            if(nums[prev] > nums[curr]) forward = false;

        }
        if(forward){
            ans = min({ans,zero ,n-zero+2});
        }

// check in backward dirrection of the array
        bool back = true;
        for(int i =1; i<n;i++){
            int prev = (zero - (i-1) + n )%n;
            int curr = (zero -i+n)%n;
            if(nums[prev] > nums[curr]) back = false;

        }
        if(back){
            ans = min({ans,zero+2,n-zero});
        }


        return ans == INT_MAX? -1 : ans;
    }
};