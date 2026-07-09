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
// class Solution {
// public:
// TreeNode* prev=NULL;

// bool inorder(TreeNode* root){
//     if(root==NULL){
//         return true;
//     }
//     if(!inorder(root->left))
//       return false;

//       if(prev!=NULL && prev->val>=root->val)
//       return false;
//       prev=root;
//       return inorder(root->right);

// }
//     bool isValidBST(TreeNode* root) {
//         return inorder(root);

        
//     }
// };


class Solution {
public:

    bool check(TreeNode* root, long long minVal, long long maxVal) {

        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};