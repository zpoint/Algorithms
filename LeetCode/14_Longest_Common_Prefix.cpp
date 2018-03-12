#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		std::size_t min_size = -1, end = 0;
        char common_c;
        std::string min_str;
		if (not strs.size())
				return "";
        for (const std::string &str : strs)
            if (str.size() < min_size)
            {
                min_size = str.size();
                min_str = str;
            }
        for (std::size_t index = 0; index < min_size; ++index, ++end)
        {
			std::size_t per_index = 0;
            for (const std::string &str : strs)
            {
                if (per_index++ == 0)
                    common_c = str[end];
                else if (str[end] != common_c)
                    return str.substr(0, end);
            }
        }
        return min_str;
    }
};

int main()
{
		Solution s;
		std::vector<std::string> sample = {""};
		std::cout << s.longestCommonPrefix(sample) << std::endl;
		return 0;
}
