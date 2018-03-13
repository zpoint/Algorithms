#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
	   std::sort(nums.begin(), nums.end());
       int cloest = ~(1 << 31), prev_index = -1, rest, sum, cloest_sum = target;
	   std::size_t nums_size = nums.size();
	   for (int index = 0; index < (int)nums_size - 2; ++ index)
	   {
			   if (index != 0 and nums[index] == nums[prev_index])
					   continue;
			   prev_index = index;
			   std::size_t two_left, two_right;
			   rest = target - nums[index];
			   for (two_left = index + 1, two_right = nums_size - 1; two_left < two_right; )
			   {
					   sum = nums[two_left] + nums[two_right];
					   if (sum == rest)
							   return target;
					   else if (sum < rest)
							   ++two_left;
					   else
							   --two_right;
					   if (std::abs(rest - sum) < cloest)
					   {
							   cloest = std::abs(rest - sum);
							   cloest_sum = sum + nums[index];
					   }
					   //std::cout << "index: " << index << " two_left: " << two_left << " two_right: " << two_right << " cloest: " << cloest << " cloest_sum: " << cloest_sum << std::endl;
			   }
	   }
	   return cloest_sum;
    }
};

int main()
{
		std::vector<int> ivec = {-1,0,1,1,55};
		Solution s;
		std::cout << s.threeSumClosest(ivec, 3) << std::endl;
		return 0;
}
