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
    void getAns(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        invertTree(root->right);
        
        invertTree(root->left);
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=temp;

    }
    TreeNode* invertTree(TreeNode* root) {

        getAns(root);
        return root;
        
    }
};