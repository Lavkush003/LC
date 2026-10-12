// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//    ListNode* reverse(ListNode* head, int times) {
//     ListNode* curr = head;
//     ListNode* prev = NULL;

//     while (times--) {
//         ListNode* next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     head->next = curr;
//     return prev;
// }
// public:
//     ListNode* swapPairs(ListNode* head) {

//         if(head==NULL){
//             return NULL;
//         }
//         ListNode* left=head;
//         ListNode* right;
//         ListNode* res=NULL;
//         ListNode* prevleft=NULL;
//         int size=2;

//         while(true){
//             right=left;
//             for(int i=0;i<size-1;i++){
//                 if(right==NULL)
//                 break;
//                 right=right->next;
//             }
//             if(right){
//                 ListNode* nextleft=right->next;
//                 right = reverse(left, size);
//                 if(prevleft)
//                 prevleft=left;
//                 if(res==NULL)
//                 res=right;
//                 left=nextleft;
//             }else{
//                 if(prevleft)
//                 prevleft->next = right;
//                 prevleft = left;
//                 if(res==NULL)
//                 res=left;
//                 break;
//             }
//         }
//         return res;
        
//     }
// };



class Solution {
    ListNode* reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = curr;
        return prev;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        int size = 2;

        while (true) {
            right = left;
            for (int i = 0; i < size - 1; i++) {
                if (!right) break;
                right = right->next;
            }

            if (right) {
                ListNode* nextleft = right->next;
                right = reverse(left, size);

                if (prevleft)
                    prevleft->next = right;

                if (res == NULL)
                    res = right;

                prevleft = left;
                left = nextleft;
            } else {
                if (prevleft)
                    prevleft->next = left;

                if (res == NULL)
                    res = left;

                break;
            }
        }

        return res;
    }
};