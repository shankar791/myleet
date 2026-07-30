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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode *first = head, *last = head;
        int len = 0;

        while (last != nullptr) {
            last = last->next;
            len++;
        }

        for (int i = 1; i < len / 2; i++) {
            first = first->next;
        }

        if (len % 2 != 0)
            first = first->next;

        ListNode *prev = nullptr;
        ListNode *curr = first->next;

        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        first->next = prev;
        ListNode *check = first->next;

        while (check != nullptr) {
            if (head->val != check->val)
                return false;
            head = head->next;
            check = check->next;
        }

        return true;
    }
};