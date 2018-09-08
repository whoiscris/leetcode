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
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int mx = nums[l];
        int mx_pos = l;
        for (int i=l; i<=r; ++i) {
            if (nums[i] > mx) {
                mx = nums[i];
                mx_pos = i;
            }
        }
        TreeNode* n = new TreeNode(mx);
        n->left = helper(nums, l, mx_pos-1);
        n->right = helper(nums, mx_pos+1, r);
    
        return n;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
