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
    int findDepth(TreeNode* root, int x, int& parent, int depth) {
        if (root == nullptr) return depth;
        if (root->val == x) {
            return depth;
        }
        else if (root->left && root->left->val == x) {
            parent = root->val;
            return depth+1;
        }
        else if (root->right && root->right->val == x) {
            parent = root->val;
            return depth+1;
        }
        else if (!root->left && !root->right) {
            return 0;
        }

        int left_depth = 0;
        if (root->left) {
            left_depth = findDepth(root->left,x,parent,depth+1);
        }
        int right_depth = 0;
        if (left_depth==0 && root->right) {
            right_depth = findDepth(root->right,x,parent,depth+1);
        }
        
        return max(left_depth, right_depth);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        //find depth of two nodes along with there parents
        //if depth are same ant parents are differerent then true
        int parent_x = INT_MIN;
        int parent_y = INT_MIN;
        int depth_x = 0;
        int depth_y = 0;
        depth_x = findDepth(root, x, parent_x, depth_x);
        depth_y = findDepth(root, y, parent_y, depth_y);
        if ((depth_x == depth_y) && (parent_x != parent_y)) return true;
        return false;
    }
};