
// BFS (level-order-traversal)

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
        int maxDepth(TreeNode* root) {
           if(root == nullptr){
                return 0;
            }
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;
    
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    TreeNode * currentElement = q.front();
                    q.pop();
    
                    if(currentElement->left != nullptr){
                        q.push(currentElement->left);
                    }
                    if(currentElement->right != nullptr){
                        q.push(currentElement->right);
                    }
                }
                level = level + 1;
            }
            return level; 
        }
    };


// DFS (depth first-search-algorihtm)

