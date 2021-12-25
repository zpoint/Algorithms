class Solution {
public:
    bool isValid(string s) {
        int l1 = 0, l2 = 0, l3 = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++l1;
            } else if (c == '{') {
                ++l2;
            } else if (c == '[') {
                ++l3;
            } else if (c == ')') {
                if (l1 <= 0) {
                    return false;
                }
                --l1;
            } else if (c == '}') {
                if (l2 <= 0) {
                    return false;
                }
                --l2;
            } else if (c == ']') {
                if (l3 <= 0) {
                    return false;
                }
                --l3;
            }
            else {
                return false;
            }
        }
        return l1 == 0 and l2 == 0 and l3 == 0;
        
    }
};
