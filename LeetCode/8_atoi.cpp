#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        bool minus = false;
        long old_result = 0, new_result = 0;
        int int_max = (long)(1 << 31) - 1;
        int int_min = 1 << 31;
        bool has_sign = false;
        bool is_num = false;

        for (const auto c : s) {
            if (c == '+' or c == '-') {
                if (has_sign) {
                    break;
                }
                if (is_num) {
                    break;
                }
                has_sign = true;
                minus = c == '-';
                continue;
            } else if (c == ' ') {
                if (is_num or has_sign) {
                    break;
                } else {
                    continue;
                }

            } else if (c < 48 or c > 57) {
                break;
            }

            new_result = (old_result * 10) + (c - 48);
            // std::cout << "c: " << c << " result: " << new_result << " int_max: " << int_max << std::endl;
            if (new_result >= int_max) {
                return minus ? (new_result == int_max ? (new_result * -1) : int_min) : int_max;
            }
            old_result = new_result;
            is_num = true;
        }
        return minus ? (new_result * -1) : new_result;
    }
};

int main() {
    Solution s;
    std::cout << s.myAtoi("4193 with words") << std::endl;
    std::cout << s.myAtoi("-2147483647") << std::endl;
    std::cout << s.myAtoi("123-") << std::endl;
    std::cout << s.myAtoi("  +  413") << std::endl;
}


