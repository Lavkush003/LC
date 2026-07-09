/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   void buildBST(TreeNode* root, TreeNode* newNode){
    TreeNode* curr=root;

    while(true){
    if(newNode->val<curr->val){
        if(curr->left==NULL){
            curr->left=newNode;
            break;
        }
        curr=curr->left;
    }
    else{
        if(curr->right==NULL){
            curr->right=newNode;
            break;
        }
        curr=curr->right;
    }
   }
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        if(preorder.size()==1){
            return root;
        }

        for(int i=1;i<preorder.size();i++){
            TreeNode* newNode= new TreeNode(preorder[i]);
            buildBST(root,newNode);
        }
        return root;
        

    }
};