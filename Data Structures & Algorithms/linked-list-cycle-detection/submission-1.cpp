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
    bool hasCycle(ListNode* head) {
        // linkedlist-head
    // return bool
    
    // keep a listed of visited nodes
    // if encountereted one among them we have a cycle

    unordered_set<ListNode*> seen;
    ListNode* curr = head;

    while(curr){
        if(seen.find(curr) != seen.end()){
            return true;
        }

        seen.insert(curr);
        curr = curr-> next;
    }

    return false;
    }
};