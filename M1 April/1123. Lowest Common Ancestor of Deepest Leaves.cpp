/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
               if(root == NULL){
                    return NULL;
               }
    
                root->left = lowestCommonAncestor(root->left,p,q);
                root->right = lowestCommonAncestor(root->right,p,q);
                if(root == p or root == q){
                    return root;
                }
    
                if(root->left && root->right){
                    return root;
                }
                // agar root ka left nullptr hai
                // then we need to return root ka right node (wahan se mil jaye)
               return root->left == NULL ? root->right:root->left;
        }
    };