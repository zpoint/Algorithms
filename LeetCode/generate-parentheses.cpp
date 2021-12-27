/*
1 1
2 2
3 5
n 3(n-1)-1
*/

std::vector<std::string> vec1 = {"()"};
std::vector<std::string> vec2 = {"()()", "(())"};
std::vector<std::string> vec3 = {"((()))","(()())","(())()","()(())","()()()"};


class Solution {
public:
    void helper(int begin, int close, int n, std::vector<string> &ret, std::string& tmp) {
        if (begin == n and close == n) {
            ret.push_back(tmp);
            return;
        }

        if (begin < n) {
            tmp.push_back('(');
            helper(begin+1, close, n, ret, tmp);
            tmp.pop_back();
        }

        if (close < n and close < begin) {
            tmp.push_back(')');
            helper(begin, close+1, n, ret, tmp);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return vec1;
        } else if (n == 2) {
            return vec2;
        } else if (n == 3) {
            return vec3;
        }
        std::vector<string> vec_end;
        std::string tmp;
        helper(0, 0, n, vec_end, tmp);
        return vec_end;
    }
};
