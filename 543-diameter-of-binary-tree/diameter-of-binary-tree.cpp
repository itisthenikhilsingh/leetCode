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
    int high(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return max(high(root->left),high(root->right))+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int right=diameterOfBinaryTree(root->right);
        int left=diameterOfBinaryTree(root->left);
        int total=high(root->right)+high(root->left);

        return max(total,max(left,right));
        
    }
};