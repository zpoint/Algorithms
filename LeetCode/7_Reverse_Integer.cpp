#include <iostream>

const unsigned INT_M ((unsigned)-1 / 2);

class Solution {
public:
    int reverse(int x) {
        int sign;
        unsigned a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, unsigned_val, index = 0, max_index = 0;
        unsigned long dest_val = 0, base = 1;
        if (x > 0)
        {
            unsigned_val = x;
            sign = 1;
        }
        else
        {
            unsigned_val = x * -1;
            sign = -1;
        }
		//std::cout << unsigned_val << " " << std::endl;
        while (unsigned_val > 0)
        {
            a[index++] = unsigned_val % 10;
			//std::cout << a[index - 1] << " ";
            unsigned_val /= 10;
            max_index++;
        }
		//std::cout << std::endl;
        for (int i = max_index - 1; i >= 0; --i)
        {
            dest_val += a[i] * base;
			//std::cout << dest_val << " ";
            base *= 10;
        }
        if (dest_val > INT_M)
            return 0;
        else
            return dest_val * sign;
    }
};

int main()
{
	Solution s;
	std::cout << s.reverse(32768) << std::endl;
	return 0;
}
