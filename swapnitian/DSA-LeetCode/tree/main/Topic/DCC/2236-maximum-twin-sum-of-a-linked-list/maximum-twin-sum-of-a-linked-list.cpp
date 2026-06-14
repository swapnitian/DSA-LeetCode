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
    int pairSum(ListNode* head) {
        int idx = 0;
        ListNode* node = head;
        vector<int> v;
        while(node != NULL){
            v.push_back(node->val);
            node = node->next;
        }
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            ans = max(ans , v[i]+v[n-i-1]);
        }
        return ans;
    }
};