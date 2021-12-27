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
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return vec1;
        } else if (n == 2) {
            return vec2;
        } else if (n == 3) {
            return vec3;
        }
        std::vector<std::string> vec_new = vec3;
        std::set<std::string> set_new;
        auto vec_old = vec_new;
        vec_new.reserve(3 * (n - 1) - 1);
        vec_old.reserve(3 * (n - 1) - 1);

        for (int i = 3; i < n; ++i) {
            int index = 0;
            int vec_old_size = vec_old.size();
            for (const auto& str : vec_old) {
                const auto left = "()" + str;
                const auto right = str + "()";
                const auto mid = "(" + str + ")";

                if (set_new.find(left) == set_new.end()) {
                    if (index < vec_old_size) {
                        vec_new[index++] = left;
                    } else {
                        vec_new.push_back(left);
                    }
                    set_new.insert(left);
                }


                if (index < vec_old_size) {
                    vec_new[index++] = mid;
                } else {
                    vec_new.push_back(mid);
                }
                set_new.insert(mid);

                if (set_new.find(right) == set_new.end()) {
                   if (index < vec_old_size) {
                        vec_new[index++] = right;
                    } else {
                        vec_new.push_back(right);
                    }
                    set_new.insert(right);
                }
            }
            vec_old = vec_new;
        }
        return vec_new;
    }
};
