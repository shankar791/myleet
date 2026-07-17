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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* sup=head;
        while(temp!=nullptr){
            ListNode* x=temp->next;
            ListNode* y=temp;
            temp->next=head;
            temp=x;
            head=y;
        }
        sup->next=nullptr;
        
        return head;
    }
};