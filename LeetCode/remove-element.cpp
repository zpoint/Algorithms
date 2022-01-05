class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int head = 0, tail = nums.size()-1, tmp = 0;
        if (tail < 0) {
            return 0;
        }
        
        while (head < tail) {
            if (nums[head] == val) {
                nums[head] = nums[tail];
                --tail;
            } else {
                ++head;
            }
        }
        
        if (head == tail and nums[head] == val) {
            return head;
        }
        
        return head+1;
    }
};
