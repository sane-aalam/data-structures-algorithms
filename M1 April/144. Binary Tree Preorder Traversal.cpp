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
    private:
        void helper(TreeNode* root, vector<int> & preorderContainer){
             if(root == NULL){
                return;
             }
    
            // Store the node, go to left, go the right;
             preorderContainer.push_back(root->val);
             helper(root->left,preorderContainer);
             helper(root->right,preorderContainer);
        }
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> preorderContainer;
            helper(root,preorderContainer);
            return preorderContainer;
        }
    };