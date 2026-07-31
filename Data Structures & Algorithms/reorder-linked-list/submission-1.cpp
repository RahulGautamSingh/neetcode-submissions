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
    void reorderList(ListNode* head) {
          // singly LL
    // reorder nodes

    // create a vector with all the nodes
    // traverse the vector and re-assign the next for each node to as needed
    // i=0 it should point to j=n-1 which inturn should point to i=1
    // ie. position stays same we just re-assign the 
    if(!head) return;
    vector<ListNode*> nodes;
    ListNode* curr = head;

    while(curr){
        nodes.push_back(curr);
        curr = curr->next;
    }

    int i=0, j=nodes.size() - 1;
    while(i<j){
        nodes[i]->next = nodes[j];
        i++;
        if(i>=j) break;

        nodes[j]->next = nodes[i];
        j--;
    }

    nodes[i]->next = nullptr;
    }

 
};