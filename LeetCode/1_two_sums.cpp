#include <map>
#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> ret_nums;
		std::multimap<int, int> imap;
		std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> ret;
		int index = 0, rest = 0;
        for (auto &i : nums)
            imap.insert(std::make_pair(i, index++));
		index = 0;
		for (auto &i : nums)
		{
				rest = target - i;
				ret = imap.equal_range(rest);
				for (std::multimap<int, int>::iterator it=ret.first; it != ret.second; ++it)
				{
						if (it->second != index)
						{
								// find target and target is not self
								ret_nums.push_back(index);
								ret_nums.push_back(it->second);
								return ret_nums;
						}
				}
				++index;
		}
		return ret_nums;
    }
};

int main()
{
		std::vector<int> ivec = {3, 3, 4};
		Solution s = Solution();
		std::vector<int> results = s.twoSum(ivec, 6);
		for (auto &i : results)
		{
				std::cout << i << std::endl;
		}
		return 0;
}
