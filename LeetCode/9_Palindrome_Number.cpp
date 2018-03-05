#include <iostream>
#define LEN_INT 10
using namespace std;

int i_arr[LEN_INT];

class Solution {
public:
    bool isPalindrome(int x) {
        long val = (long)x;
        std::size_t index = 0;
        if (val < 0)
            return false;
        while (val > 0)
        {
            i_arr[index++] = val % 10;
            val /= 10;
        }
        for (std::size_t b = 0, e = index-1; b <= e and b < LEN_INT and e < LEN_INT; ++b, --e)
        {
            if (i_arr[b] != i_arr[e])
                return false;
        }
        return true;
    }
};

int main()
{
		Solution s;
		std::cout << s.isPalindrome(-1) << std::endl;
		return 0;
}
