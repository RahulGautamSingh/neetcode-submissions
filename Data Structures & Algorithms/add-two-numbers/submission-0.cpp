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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // two non-empty LLs
        // reverse after collecting to get number

        // will they be equal size?
        // should not matter. if only one remains then just keep it

        int carry = 0;
        ListNode l3;
        ListNode* curr = &l3;

        while(l1 || l2 || carry){
           int sum = carry;
           if(l1) {
            sum += l1->val; l1 = l1->next;
           }
           if(l2) {
            sum += l2->val; l2 = l2->next;
           }

           carry = sum/10;
           curr->next = new ListNode(sum%10);
           curr = curr->next;
        }

        return l3.next;
    }
};
