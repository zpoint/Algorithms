/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <pair>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// index, value

class MinHeap {
private:
    std::vector<std::pair<int, int>> curr_vec;

public:
    MinHeap(const std::vector<std::pair<int, int>> &vec) { this->build(vec);}
    void build(const std::vector<std::pair<int, int>> &vec);
    std::pair<int, int> pop();
    void insert(const std::pair<int, int> &pair);
    len() { return curr_vec.size(); };

}


void MinHeap::build(const std::vector<std::pair<int, int>> &vec) {
    for (const auto&pair : vec) {
        this->insert(pair);
    }
}

std::pair<int, int> MinHeap::pop() {
    // boundary check
    auto tmp = curr_vec[0];
    if (curr_vec.size() == 1) {
        curr_vec.clear();
        return tmp;
    }

    curr_vec[0] = curr_vec[curr_vec.size()-1];
    // sift down
    auto new_tail = curr_vec.pop_back();
    int index = 0, down_index = 1, max_index = curr_vec.size();
    curr_vec[0] = new_tail;
    while (down_index <= max_index) {
        if (new_tail.second > curr_vec[down_index].second) {
            auto tmp2 = curr_vec[down_index];
            curr_vec[down_index] = new_tail;
            curr_vec[index] = tmp2;
        } else if (down_index+1 <= max_index and new_tail.second > curr_vec[down_index+1].second) {
            auto tmp2 = curr_vec[down_index+1];
            curr_vec[down_index+1] = new_tail;
            curr_vec[index] = tmp2;
        } else {
            break;
        }
        index = (index+1)*2 - 1;
        down_index = (index+1)*2 - 1;
    }

    return tmp;
}

void MinHeap::insert(const std::pair<int, int> &pair) {

    // sift up
    curr_vec.push_back(pair);
    int index = curr_vec.size()-1, up_index = int((index-1) / 2), max_index = curr_vec.size();

    if (index == 0) {
        return;
    }

    while (up_index >= 0) {
        if (pair.second < curr_vec[up_index].second) {
            auto tmp2 = curr_vec[up_index];
            curr_vec[up_index] = new_tail;
            curr_vec[index] = tmp2;
        } else if (up_index+1 <= max_index and pair.second < curr_vec[up_index+1].second) {
            auto tmp2 = curr_vec[up_index+1];
            curr_vec[up_index+1] = new_tail;
            curr_vec[index] = tmp2;
        } else {
            break;
        }
        index = int((index-1) / 2);
        up_index = index > 0 ? int((index-1) / 2) : -1;
    }

}

class Solution {
public:


    ListNode* mergeKLists(vector<ListNode*>& lists) {

    }
};
