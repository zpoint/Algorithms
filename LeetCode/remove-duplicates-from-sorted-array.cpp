class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int max_size = nums.size();
        int i = 0;
        for (int j = 1; j < max_size; ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                if (j - i > 0) {
                    nums[i] = nums[j];
                }
            }
        }
        return max_size == 0 ? max_size : (i+1);
    }
};
