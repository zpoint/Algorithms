#include <iostream>
#include <cstdlib>

using namespace std;

std::size_t head[1000*1000];

class Solution {
public:
    string longestPalindrome(string s) {
		const std::size_t s_size = s.size();
		std::size_t row_head, row_end, mid_length;
        //std::size_t* head = (std::size_t *)malloc(sizeof(std::size_t) * s.size() * s.size());
		for (std::size_t length = 0; length < s_size; ++length)
		{
				for (std::size_t begin = 0; begin < s_size; ++begin)
				{
						row_head = begin * s_size + begin;
						row_end = row_head + length;
						if (length == 0)
						{
								head[row_head] = 1;
						}
						else if (begin + length < s_size)
						{
								if (length == 1)
								{
										head[row_end] = s[begin] == s[begin + length] ? 2 : 0;
										continue;
								}
								mid_length = head[(begin + 1) * s_size + begin + 1 + length - 2];
								if (s[begin] == s[begin + length] and mid_length == (row_end - row_head - 1))
										head[row_end] = mid_length + 2;
								else
										head[row_end] = 0;
						}
						else
								continue;
				}
		}
		std::size_t max = 0, max_b = 0, max_length = 0;
		for (std::size_t begin = 0; begin < s_size; ++begin)
		{
				for (std::size_t length = begin; length < s_size; ++length)
				{
						//std::cout << head[begin * s_size + length] << " ";
						if (head[begin * s_size + length] > max)
						{
								max = head[begin * s_size + length];
								max_b = begin;
								max_length = length - begin + 1;
						}
				}
				//std::cout << "\n";
		}
		//std::cout << "max_b: " << max_b << " max_length: " << max_length << std::endl;
		return s.substr(max_b, max_length);
	}

};

int main()
{
		Solution s;
		std::cout << s.longestPalindrome("abcba") << std::endl;
		return 0;
}

