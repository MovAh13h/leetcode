class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        const int size = nums.size();
        for (int i = 0; i < size; ++i) {
            const int diff = target - nums[i];
            if (m.count(diff)) {
                return {i, m[diff]};
            }
            m[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};