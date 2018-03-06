#include <iostream>
#include <vector>
using namespace std;

#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        std::size_t i = s.size(), j = p.size();
        std::vector<std::vector<bool>> T(i+1, std::vector<bool>(j+1, false));
        T[0][0] = true;
		for (std::size_t col = 1; col <= j; ++col)
				if (p[col-1] == '*')
						T[0][col] = T[0][col-2];

        for (std::size_t row = 1; row <= i; ++row)
        {
            for (std::size_t col = 1; col <= j; ++col)
            {
                if (p[col-1] == '*')
                    // zero or more
                    T[row][col] = T[row][col-2] or ((s[row-1] == p[col-2] or p[col-2] == '.') and T[row-1][col]);
                else
                    T[row][col] = (s[row-1] == p[col-1] or p[col-1] == '.') and T[row-1][col-1];
            }
        }
        return T[i][j];
    }
};

int main()
{
		Solution s;
		std::cout << s.isMatch("aa", ".*") << std::endl;
		return 0;
}
