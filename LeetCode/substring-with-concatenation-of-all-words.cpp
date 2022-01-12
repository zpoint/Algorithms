class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result_vec;
        if (words.size() == 0) {
            return result_vec;
        }

        std::set<char> first_char_set;
        std::map<std::string, int> result_map;
        auto size = words[0].size();

        for (const auto& word : words) {
            first_char_set.insert(word[0]);
        }

        int max_index = s.size() - size * words.size();
        if (max_index < 0) max_index = 0;
        for (auto index = 0; index <= max_index; ++index) {
            bool has_result = true;
            result_map.clear();
            for (const auto& word : words) {
                if (result_map.find(word) == result_map.end()) {
                    result_map[word] = 1;
                } else {
                    result_map[word] += 1;
                }
            }

            for (auto index_j = index; index_j < (index + size * words.size()); ++index_j) {
                const auto& word = s.substr(index_j, size);
                // std::cout << "index: " << index << " index_j: " << index_j << " word: " << word << std::endl;
                if (first_char_set.find(word[0]) != first_char_set.end()) {
                    if (result_map.find(word) != result_map.end()) {
                        result_map[word] -= 1;
                        index_j += (size - 1);
                    } else {
                        // not hit
                        has_result = false;
                        break;
                    }
                } else {
                    // not hit
                    has_result = false;
                    break;
                }
            }

            if (has_result) {
                // check if hit
                for (const auto& word : words) {
                    if (result_map[word] > 0) {
                        has_result = false;
                        break;
                    }
                }
            }

            if (has_result) {
                result_vec.push_back(index);
            }

        }
        return result_vec;
    }
};
