class Solution {
public:
    int length(const std::string s) {
        int result = 0;
        int result_archive = 0;
        std::stack<char> p_stack;
        for (const char &c : s) {
            // std::cout << "c: " << c << std::endl;
            if (c == '(') {
                p_stack.push(c);
            } else if (c == ')') {
                if (p_stack.empty()) {
                    return result;
                }
                if (p_stack.top() == '(') {
                    p_stack.pop();
                    result += 2;
                }
                if (p_stack.empty()) {
                    result_archive = result;
                }
            } else {
                break;
            }
        }
        if (!p_stack.empty()) {
            return result_archive;
        }
        return result;
    }

    int longestValidParentheses(string s) {
        int result = 0;
        size_t size = s.size();
        for (int i = 0; i < size; ++i) {
            auto r = s.substr(i, size-i);
            // std::cout << "r: " << r << std::endl;
            int curr_result = length(r);
            if (curr_result > result) {
                result = curr_result;
            }
        }
        return result;
    }
};
