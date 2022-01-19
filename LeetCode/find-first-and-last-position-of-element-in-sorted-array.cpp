class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int pivot = -1;
        std::vector<int> result{-1, -1};
        if (end == -1) {return result;}
        else if (end == 0) {if (nums[0] == target) {result[0] = 0; result[1] = 0;} return result;}

        while (start <= end) {
            int mid = (start + end) / 2;
            // std::cout << "start: " << start << " end: " << end << " mid: " << mid << std::endl;
            if (start == end) {
                if (nums[start] == target) {
                    pivot = start;
                }
                break;
            }

            if (nums[mid] == target) {
                pivot = mid;
                break;
            } else if (nums[mid] < target) {
                start = (start == mid ? mid+1 : mid);
            } else {
                end = (end == mid) ? mid-1 : mid;
            }
        }
        // std::cout << "pivot: " << pivot << std::endl;
        if (pivot != -1) {
            result[0] = result[1] = pivot;
            start = 0, end = nums.size()-1;
            int curr_low = pivot - 1, curr_high = pivot + 1;
            while (curr_low >= start and nums[curr_low] == target) {
                result[0] = curr_low;
                --curr_low;
            }
            while (curr_high <= end and nums[curr_high] == target) {
                result[1] = curr_high;
                ++curr_high;
            }
        }

        return result;
    }
};
