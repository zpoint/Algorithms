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

#include <iostream>
#include <vector>
#include <utility>

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
    int sibling_index = 0;
    if (index == 0) {
        return;
    }

    while (up_index >= 0) {
        sibling_index = index % 2 == 0 ? (index - 1) : (index + 1);
        if (sibling_index >= max_index or sibling_index < 0) {
            sibling_index = 0;
        }

        if (pair.second < curr_vec[up_index].second and not (sibling_index != 0 and pair.second > curr_vec[sibling_index].second)) {
            auto tmp2 = curr_vec[up_index];
            curr_vec[up_index] = pair;
            curr_vec[index] = tmp2;
        } else if (sibling_index != 0 and curr_vec[sibling_index].second < curr_vec[up_index].second ) {
            auto tmp2 = curr_vec[sibling_index];
            curr_vec[sibling_index] = curr_vec[up_index];
            curr_vec[up_index] = tmp2;
        } else {
            break;
        }
        index = int((index-1) / 2);
        up_index = index > 0 ? int((index-1) / 2) : -1;
    }

    /*
    std::cout << "after insert, up_index: " << up_index << "\n";
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

int main() {
    // [[-10,-9,-9,-3,-1,-1,0],[-5],[4],[-8],[],[-9,-6,-5,-4,-2,2,3],[-3,-3,-2,-1,0]]
    ListNode a1(-10), a2(-9), a3(-9), a4(-3), a5(-1), a6(-1), a7(0);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    a6.next = &a7;

    ListNode c1(-9), c2(-6), c3(-5), c4(-4), c5(-2), c6(2), c7(3);
    c1.next = &c2;
    c2.next = &c3;
    c3.next = &c4;
    c4.next = &c5;
    c5.next = &c6;
    c6.next = &c7;

    ListNode b1(-5);

    ListNode d1(4);

    ListNode e1(-8);

    ListNode f1(-3), f2(-3), f3(-2), f4(-1), f5(-0);
    f1.next = &f2;
    f2.next = &f3;
    f3.next = &f4;
    f4.next = &f5;

    Solution s;
    std::vector<ListNode*> vec{&a1, &b1, &d1, &e1, nullptr, &c1, &f1};
    auto r = s.mergeKLists(vec);
    while (r != nullptr) {
        std::cout << r->val << " ";
        r = r->next;
    }
    std::cout << std::endl;

//    ListNode f1(1);
//    std::vector<ListNode*> vec2{nullptr, &f1};
//    auto r2 = s.mergeKLists(vec2);
//    while (r2 != nullptr) {
//        std::cout << r2->val << " ";
//        r2 = r2->next;
//    }
//    std::cout << std::endl;
}
