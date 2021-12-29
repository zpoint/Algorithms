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

// index, value

class MinHeap {
private:
    std::vector<std::pair<int, int>> curr_vec;

public:
    MinHeap() {}
    MinHeap(const std::vector<std::pair<int, int>> &vec) { this->build(vec);}
    void build(const std::vector<std::pair<int, int>> &vec);
    std::pair<int, int> pop();
    void insert(const std::pair<int, int> &pair);
    size_t len() { return curr_vec.size(); };

};


void MinHeap::build(const std::vector<std::pair<int, int>> &vec) {
    for (const auto&pair : vec) {
        this->insert(pair);
    }
}

std::pair<int, int> MinHeap::pop() {
    // boundary check
    /*
    std::cout << "before pop\n";
    for (const auto& each : curr_vec) {
        std::cout << each.first << " " << each.second << "\n";
    }
     */
    auto tmp = curr_vec[0];
    if (curr_vec.size() == 1) {
        curr_vec.clear();
        // std::cout << "after pop\n";
        return tmp;
    }

    curr_vec[0] = curr_vec[curr_vec.size()-1];
    // sift down
    auto new_tail = curr_vec.back();
    curr_vec.pop_back();
    int index = 0, down_index = 1, max_index = curr_vec.size();
    curr_vec[0] = new_tail;
    while (down_index <= max_index) {
        if (new_tail.second > curr_vec[down_index].second and not (down_index+1 <= max_index and curr_vec[down_index+1].second < curr_vec[down_index].second)) {
            auto tmp2 = curr_vec[down_index];
            curr_vec[down_index] = new_tail;
            curr_vec[index] = tmp2;
            index = (index+1)*2 - 1;
        } else if (down_index+1 <= max_index and new_tail.second >= curr_vec[down_index+1].second) {
            auto tmp2 = curr_vec[down_index+1];
            curr_vec[down_index+1] = new_tail;
            curr_vec[index] = tmp2;
            index = (index+1)*2;
        } else {
            break;
        }
        down_index = (index+1)*2 - 1;
    }
    /*
    std::cout << "after pop\n";
    for (const auto& each : curr_vec) {
        std::cout << each.first << " " << each.second << "\n";
    }
    std::cout << std::endl;
     */
    return tmp;
}

void MinHeap::insert(const std::pair<int, int> &pair) {

    /*
    std::cout << "before insert: ";
    for (const auto& each : curr_vec) {
        std::cout << each.first << " " << each.second << "\n";
    }
    std::cout << std::endl;
     */


    // sift up
    curr_vec.push_back(pair);
    int index = curr_vec.size()-1, up_index = int((index-1) / 2), max_index = curr_vec.size();

    if (index == 0) {
        return;
    }

    while (up_index >= 0) {
        if (pair.second < curr_vec[up_index].second and not (up_index+1 <= max_index and pair.second > curr_vec[up_index+1].second)) {
            auto tmp2 = curr_vec[up_index];
            curr_vec[up_index] = pair;
            curr_vec[index] = tmp2;
        } else if (up_index+1 <= max_index and pair.second <= curr_vec[up_index+1].second) {
            auto tmp2 = curr_vec[up_index+1];
            curr_vec[up_index+1] = pair;
            curr_vec[index] = tmp2;
        } else {
            break;
        }
        index = int((index-1) / 2);
        up_index = index > 0 ? int((index-1) / 2) : -1;
    }

    /*
    std::cout << "after insert: ";
    for (const auto& each : curr_vec) {
        std::cout << each.first << " " << each.second << "\n";
    }
    std::cout << std::endl;
    */
}

class Solution {
public:


    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        MinHeap min_heap;
        int index = 0;
        ListNode* head = nullptr, *node = nullptr;
        if (lists.empty()) {
            return head;
        }


        for (const auto* each_node : lists) {
            auto curr_index = index++;
            if (each_node == nullptr) {
                continue;
            }
            min_heap.insert(std::make_pair(curr_index, each_node->val));
        }

        while (min_heap.len() > 0) {
            auto res = min_heap.pop();
            if (head == nullptr) {
                head = lists[res.first];
                node = head;
            } else {
                node->next = lists[res.first];
                node = node->next;
            }

            lists[res.first] = (lists[res.first])->next;
            if (lists[res.first] != nullptr) {
                min_heap.insert(std::make_pair(res.first, lists[res.first]->val));
            }
        }

        return head;
    }
};
