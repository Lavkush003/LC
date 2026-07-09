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
void inorderTraversal(TreeNode*root, vector<int>&inorder){
    //base case
    if(root==NULL){
        return;
    }
    //main logic
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}
TreeNode* balancedBST(int low, int high, vector<int>&inorder){
    //base case
   if(low==high){
    TreeNode* node=new TreeNode(inorder[low]);
    return node;
   }

    //edge case
    if(low>high){
        return NULL;
    }

    //main logic

    int mid=(low+high)/2;
    TreeNode* root=new TreeNode(inorder[mid]);
   TreeNode*leftnode= balancedBST(low,mid-1,inorder);
   TreeNode*rightnode= balancedBST(mid+1,high,inorder);
   root->left=leftnode;
   root->right=rightnode;
   return root;


}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int low=0;
        int high=inorder.size()-1;


        return balancedBST(low, high, inorder);
    }
};