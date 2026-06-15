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
    ListNode* MiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
    
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* middle = MiddleNode(head);

        if(head == middle) return NULL;

        ListNode* Curr = head;
        ListNode* Prev = head;

        while(Curr != NULL){
            if(Curr == middle){
                Prev->next = Curr->next;
                break;
            }
            Prev = Curr;
            Curr = Curr->next;
        }

        return head;
    }
};