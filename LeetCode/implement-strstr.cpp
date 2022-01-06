class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        auto res = haystack.find(needle);
        if (res != std::string::npos) {
            return res;
        }
        
        return -1;
    }
};
