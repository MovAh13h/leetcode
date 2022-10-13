class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> hashmap;
      int size = nums.size();
      for(int i = 0; i < size; ++i){
        if(hashmap.count(target-nums[i])){
          return {i,(hashmap[target - nums[i]])};
        }
        hashmap[nums[i]] = i;
      }
      return {};
    }
};