class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int prev_index = nums.size() - 1;
        if (prev_index < 0) {
            return;
        }
        
        while (prev_index >= 0) {
            if (nums[prev_index+1] > nums[prev_index]) {
                break;
            }
            
            --prev_index;
        }
        
        int bigger_index = prev_index+1;
        while (bigger_index < nums.size()) {
            if (nums[prev_index] > nums[bigger_index]) {
                bigger_index = bigger_index - 1;
                break;
            }
            ++bigger_index;
        }
        if (bigger_index > prev_index and bigger_index < nums.size()) {
            auto tmp = nums[bigger_index];
            nums[bigger_index] = nums[prev_index];
            nums[prev_index] = tmp;
            ++prev_index;
            bigger_index = nums.size() - 1;
        }
        
        while (prev_index < bigger_index) {
            auto tmp = nums[bigger_index];
            nums[bigger_index] = nums[prev_index];
            nums[prev_index] = tmp;
            ++prev_index;
            --bigger_index;
        }
    }
};
