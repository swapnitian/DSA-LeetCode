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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL ;
        ListNode* curr = head ;
        ListNode* next = NULL ;

        while( curr != NULL ) {
            next = curr->next ;
            curr->next = prev ;
            
            prev = curr ;
            curr = next ;
        }
        return prev ;
    }
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* slow = head;
        while(slow != NULL){
            n++;
            slow = slow->next;
        }
        int it = 0;
        ListNode* fast = head;
        while(true){
            if(it == n/2){
                fast = reverseList(fast);
                break;
            }
            fast = fast->next;
            it++;
        }
        slow = head;
        int ans = 0;
        while(slow && fast){
            ans = max(ans ,slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        return ans;
    }
};