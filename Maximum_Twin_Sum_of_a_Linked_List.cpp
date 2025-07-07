#include <iostream>
#include <vector>
#include <algorithm> 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        std::vector<int> vals;
        ListNode* curr = head;

        while (curr != nullptr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        
        int maxSum = 0;
        int n = vals.size();

        for (int i = 0; i < n / 2; ++i) {
            int twinSum = vals[i] + vals[n - 1 - i];
            maxSum = std::max(maxSum, twinSum);
        }
        
        return maxSum;
    }
};

ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::vector<int> values = {4, 2, 2, 3};  
    ListNode* head = createLinkedList(values);

    Solution solution;
    int result = solution.pairSum(head);
    std::cout << "Maximum twin sum: " << result << std::endl;

    deleteLinkedList(head);  
    return 0;
}