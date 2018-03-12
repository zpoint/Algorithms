#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
		std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
		{
				std::map<int, std::map<int, int>> r_map;
				std::sort(nums.begin(), nums.end());
				int nums_size = nums.size();
				std::vector<std::vector<int>> ret_vec;
				std::size_t prev_index = 0;

				for (int index = 0; index < nums_size - 2; ++index)
				{
						if (index != 0 and nums[prev_index] == nums[index])
						{
								prev_index = index;
								continue;
						}
						prev_index = index;
						int rest = 0 - nums[index], sum = 0;
						std::size_t prev_left = 0, prev_right = 0;
						for (std::size_t two_left = index + 1, two_right = nums_size - 1; two_left < two_right; )
						{
								// std::cout << "index: " << index << " two_left: " << two_left << " two_right: " << two_right << std::endl;
								sum = nums[two_left] + nums[two_right];
								if (sum == rest)
								{
										if (two_left == (std::size_t)index + 1 or (nums[two_left] != nums[prev_left] or nums[two_right] != nums[prev_right]))
												ret_vec.push_back({nums[index], nums[two_left], nums[two_right]});
										prev_left = two_left;
										prev_right = two_right;
										++two_left;
										--two_right;
								}
								else if (sum < rest)
								{
										prev_left = two_left;
										prev_right = two_right;
										++two_left;
								}
								else
								{
										prev_left = two_left;
										prev_right = two_right;
										--two_right;
								}
						}
				}
				return ret_vec;
		}
};

int main()
{
		// std::vector<int> ivec = {1, 1, -2};
		std::vector<int> ivec = {}; //{-1,0,1,2,-1,-4};
	    Solution s;
		for (const auto &vec : s.threeSum(ivec))
		{
				for (const auto &i : vec)
						std::cout << i << " ";
				std::cout << '\n';
		}
		return 0;
}
