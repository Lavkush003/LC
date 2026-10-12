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
ListNode* reverse(ListNode* head, int times){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(times--){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=curr;
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* left=head;
        ListNode* right;
        ListNode* res=NULL;
        ListNode* prevleft=NULL;
    
        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right==NULL)
                break;
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                right=reverse(left,k);
                if(prevleft)
                prevleft->next=right;

                if(res==NULL)
                res=right;
                prevleft=left;
                left=nextleft;
            }else{
                if(prevleft)
                prevleft->next=left;

                if(res==NULL)
                res=left;
                break;
            }
        }
         return res;
    }
};