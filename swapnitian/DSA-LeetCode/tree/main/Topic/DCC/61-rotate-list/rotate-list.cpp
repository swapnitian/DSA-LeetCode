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
    ListNode* rotateRight(ListNode* head, long long k) {
        // so my logic for this problem is that just make the entire list 
        // into cyclic means connected to everyone then for each node we 
        // we will run an loop till the k jumps required that's it ;

        long long Total_nodes = 1 ;

        if(head == NULL || head->next == NULL) return head ;
        
        ListNode *temp = head ;
        // first loop to calculate total_node and to make cycle ;
        while(temp->next != NULL){
            temp = temp->next ;
            Total_nodes++ ;
        }
        if(k%Total_nodes == 0) return head ; // check before to make cycle ;
        
        temp->next = head ; // this will make cycle 

        // now this second loop will make list k jumps ;
        
        long long jumps = Total_nodes - (k%Total_nodes) ;

        ListNode *Curr = head ;
        while(--jumps){
            Curr = Curr->next ;
        }
        temp = Curr->next ;
        Curr->next = NULL ;

        return temp ;
    }
};