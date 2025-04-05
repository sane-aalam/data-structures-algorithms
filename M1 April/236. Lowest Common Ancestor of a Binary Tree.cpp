
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

//First solve: pre-order traversal algorihtm (re-call)
//Second solve: maximum depth of binary tree(re-call)
//Third READ: LCA (what is)?
// ---------------------- solve this problem ----------------
//STEP-1: Find the dpeth of each nodes using PRE_order_traversal_algorithm 
//STEP-2: find the LCA(simple)

class Solution {
    public:
        unordered_map<int, int> mp;
        int maximumDepth = 0;
    
        TreeNode* LCA(TreeNode* root) {
            if(root == NULL || mp[root->val] == maximumDepth) {
                return root;
            }
    
            TreeNode* leftAncestor = LCA(root->left);
            TreeNode* rightAncestor = LCA(root->right);
    
            if(leftAncestor != nullptr && rightAncestor != nullptr){
                return root;
            }
    
            return leftAncestor == nullptr ? rightAncestor : leftAncestor;
        }
    
        // STEP-1 Find the dpeth of each nodes using PRE_order_traversal_algorithm 
        void findNodesDepth(TreeNode* root, int depth) {
            if(!root) {
                return;
            }
    
            maximumDepth = max(maximumDepth, depth);
            // store the depth of each node of binary tree 
            mp[root->val] = depth;
            
            // go to left side of node of binary tree
            // go the right side of node of binary tree
            findNodesDepth(root->left, depth+1);
            findNodesDepth(root->right, depth+1);
        }
        //T.C : O(n)
        //S.C : O(maximumDepth) system recursion stack space
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            int depth = 0;
            findNodesDepth(root, depth);
    
            return LCA(root);
        }
    };