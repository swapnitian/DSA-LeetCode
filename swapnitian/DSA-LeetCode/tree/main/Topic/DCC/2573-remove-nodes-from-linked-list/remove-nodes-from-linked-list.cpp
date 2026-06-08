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
    ListNode* ReverseList(ListNode* head){
        ListNode* Curr = head;
        ListNode* Prev = NULL;
        ListNode* Next = NULL;

        while(Curr != NULL){
            Next = Curr->next;
            Curr->next = Prev;

            Prev = Curr;
            Curr = Next;
        }
        return Prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* Rhead = ReverseList(head);
        ListNode* Curr = Rhead;
        ListNode* Prev = NULL;

        while(Curr != NULL){
            if(Prev != NULL && Prev->val > Curr->val){
                Prev->next = Curr->next;
            }else{
                Prev = Curr;
            }
            Curr = Curr->next;
        }
        return ReverseList(Rhead);
    }
};