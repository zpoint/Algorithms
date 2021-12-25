std::map<char, char> inverse_map{{')', '('}, {'}', '{'}, {']', '['}};

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (const auto& c : s) {
            if (!stack.empty() and (c == ')' or c == '}' or c == ']') and inverse_map[c] == stack.top()) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
