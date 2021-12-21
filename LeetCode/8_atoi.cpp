class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        bool minus = false;
        int old_result = 0, new_result = 0;
        int int_max = (long)(1 << 31) - 1;
        int int_min = 1 << 31;

        for (const auto c : s) {
            if (c == ' ' or c == '+') {
                continue;
            }
            if (c == '-') {
                minus = true;
            }

            new_result = old_result * 10 + (c - 48);
            // std::cout << "c: " << c << " result: " << new_result << " int_max: " << int_max;
            if (new_result < 0) {
                return minus ? int_min : int_max;
            }
            old_result = new_result;
        }
        return minus ? (new_result * -1) : new_result;
    }
};
