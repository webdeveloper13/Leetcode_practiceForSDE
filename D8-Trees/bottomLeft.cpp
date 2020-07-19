/*
513. Find Bottom Left Tree Value
Medium

916

138

Add to List

Share
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/
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
    void leftView(TreeNode* root,vector<int>& ans,int level,int *max_level)
    {
            if(!root)
                    return;
            if(level>*max_level)
            {
                    ans.push_back(root->val);
                    *max_level = level;
            }
            
            leftView(root->left,ans,level+1,max_level);
            leftView(root->right,ans,level+1,max_level);
            
    }
public:
    int findBottomLeftValue(TreeNode* root) {
            vector<int> ans;
            int max_level = 0;
            leftView(root,ans,1,&max_level);
            return ans[ans.size()-1];
        
    }
};