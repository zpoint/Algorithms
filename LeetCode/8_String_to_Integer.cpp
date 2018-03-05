#include <iostream>
#include <string>

using namespace std;

unsigned I_MAX = ~(1 << 31);
std::size_t S_MAX = -1;

inline bool valid_num(char x)
{
    return (x <= '9' and x >= '0');
}

inline bool whitespace(char x)
{
    return x == ' ';
}

inline bool isplus(char x)
{
    return x == '+';
}

inline bool isminus(char x)
{
    return x == '-';
}

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        std::size_t start_index = 0, end_index = -1, base = 1, ret_val = 0;
        bool begin = false;
        for (const char &i : str)
        {
            if (not begin)
            {
                if (whitespace(i))
				{
					start_index += 1;
                    continue;
				}
                else if (isplus(i))
                {
                    begin = true;
                    sign = 1;
					start_index += 1;
                }
                else if (isminus(i))
                {
					start_index += 1;
                    begin = true;
                    sign = -1;
                }
                else if (valid_num(i))
                {
                    begin = true;
                    if (end_index == S_MAX)
                        end_index = start_index;
                }
                else
                    return 0;
            }
            else if (valid_num(i))
            {
                if (end_index == S_MAX)
                    end_index = start_index;
                else
                    ++end_index;
            }
            else
                break;
        }
        if (end_index == S_MAX)
            return 0;
        for (std::size_t i = end_index; i >= start_index; --i)
        {
			if (i == S_MAX)
					break;
            ret_val += base * (str[i] - '0');
            if (ret_val > I_MAX)
                return sign > 0 ? I_MAX : (-I_MAX-1);
            base *= 10;
        }
        return ret_val * sign;
    }
};

int main()
{
		Solution s;
		std::cout << s.myAtoi("-1") << std::endl;
		return 0;
}
