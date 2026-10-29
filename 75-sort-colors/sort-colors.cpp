class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 , mid = 0 , high = nums.size() - 1 ;

        while(mid<= high){
            if(nums[mid] == 0){
                int tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;

            }else{
                int tmp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = tmp;
                high--;
               
            }
        }
        // return nums;
    }
};


    // The Dutch National Flag (DNF) algorithm is a highly efficient, linear-time sorting method designed to partition an array of three distinct values into three ordered groups. Originally proposed by computer scientist Edsger Dijkstra, it is most famously used to solve the "Sort an Array of 0s, 1s, and 2s" problem

// 1. Initialize low = 0, mid = 0, and high = n - 1.
// 2. Loop while mid <= high. Examine the element at arr[mid] and act based on its value:

// Element at arr[mid]	Action Taken	Why?
// 0	Swap arr[low] and arr[mid]. 
// Increment both low++ and mid++.	Moves the 0 to the lower boundary, extending the 0s zone.
// 1	Do nothing. 
// Increment mid++.	The 1 is already in the correct relative middle position.
// 2	Swap arr[mid] and arr[high]. 
// Decrement high--. (Do not increment mid)	Moves the 2 to the upper boundary. We don't advance mid because the newly swapped element coming from high is unexamined and must be processed on the next iteration.
        