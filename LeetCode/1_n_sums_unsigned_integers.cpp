#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <numeric>
#include <iostream>

using namespace std;
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret_vals;
        std::vector<std::size_t> sorted_index = sort_indexes(nums);
        std::map<int, int> imap;
        for (int i = 0; i < (int)sorted_index.size(); ++i)
            imap[sorted_index[i]] = i;
        // malloc row
        char **table = (char **)std::malloc(sizeof(char *) * nums.size());
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            // malloc column
            char *column = (char *)std::malloc(sizeof(char) * (target + 1));
            table[i] = column;
            for (int j = 0; j <= target; ++j)
            {
                if (j == 0)
                    column[j] = 1;
                else if (i == 0)
                    column[j] = nums[i] == j ? 1 : 0;
                else if (nums[i] > j)
                    column[j] = table[i - 1][j];
                else
                    column[j] = table[i - 1][j - nums[i]];
				//std::cout << int(column[j]) << " ";
            }
			std::cout << std::endl;
            
            if (column[target]) // bingo
            {
                int search_index = i;
                int rest_val = target - nums[search_index];
                ret_vals.push_back(imap[search_index]);
                while (search_index-- >= 0 && rest_val > 0)
                {
                    if (search_index == 0)
                    {
                        ret_vals.push_back(imap[search_index]);
                        rest_val -= nums[search_index];
                    }
                    else if (!table[search_index - 1][rest_val])
                    {
                        ret_vals.push_back(imap[search_index]);
                        rest_val -= nums[search_index];
                    }
                }
                break;
            }
        }
        // free table
        return ret_vals;
    }
};

int main()
{
		std::vector<int> ivec = {3, 2, 4};
		Solution s;
		std::vector<int> result = s.twoSum(ivec, 6);
		for (auto & i : result)
				std::cout << i << std::endl;
		return 0;
}
