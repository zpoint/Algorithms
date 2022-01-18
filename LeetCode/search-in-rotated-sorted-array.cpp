class Solution {
public:
    int bin_search(vector<int>& nums, int start, int end, int target) {
        if (start > end) { return -1; }
        if (start == end) { return nums[start] == target ? start : -1; }
        while (start <= end) {
            int mid = (start + end) / 2;
            // std::cout << "start: " << start << " end: " << end << " mid: " << mid << std::endl;
            if (nums[mid] == target) { return mid; }
            else if (nums[mid] < target) { start == mid ? start = mid+1 : start = mid;}
            else {end == mid ? end = mid-1 : end = mid;}
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int pivot = end;
        if (end < 0) {
            return -1;
        } else if (end == 0) {
            return nums[0] == target ? 0 : -1;
        }

        for (int i = 0; i < end; ++i) {
            if (i == 0) { if(nums[1] < nums[0]) {pivot = 0;} else {continue;}; break; }
            else if (i == end) { break; }

            if (nums[i-1] < nums[i] and nums[i+1] < nums[i]) {
                pivot = i;
                break;
            }
        }

        // std::cout << "pivot: " << pivot << std::endl;
        if (nums[pivot] == target) { return pivot; }
        else if (nums[pivot] < target) { return -1; }
        else {
            if (target >= nums[0] and target < nums[pivot]) {
                return bin_search(nums, 0, pivot, target);
            } else {
                return bin_search(nums, pivot+1, nums.size()-1, target);
            }

        }

    }
};
