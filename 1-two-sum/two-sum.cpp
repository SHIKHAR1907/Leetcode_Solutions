class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> m;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = m.find(need);
            if (it != m.end()) return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};