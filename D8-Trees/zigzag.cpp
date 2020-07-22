/*
 Binary Tree Zigzag Level Order Traversal

Solution
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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

/*Approach
Maintain 2 stacks s1 and s2.
Initially push root to stack s1
And now until both stacks are empty keep doing this - 
while stack s1 is not empty
pop the top element push it to temp vector
then if left,right child exists for this then push them on stack 2(first left then right)

now once s1 is empty
push temp vector to answer vector

now while s2 is not empty
pop the top element push it to temp vector
then if right,left child exists for this then push them on stack 1(first right then left)
now once s2 is empty
push temp vector to answer vector
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {    
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<vector<int>> ans;
        if(!root)
                return ans;
        s1.push(root);
        vector<int> temp;    
        while(!s1.empty()||!s2.empty())
        {
                while(!s1.empty())
                {
                        auto node = s1.top();
                        s1.pop();
                        temp.push_back(node->val);
                        if(node->left)
                                s2.push(node->left);
                        if(node->right)
                                s2.push(node->right);
                }
                
                ans.push_back(temp);
                temp.clear();
                while(!s2.empty())
                {
                        auto node = s2.top();
                        s2.pop();
                        temp.push_back(node->val);
                        if(node->right)
                                s1.push(node->right);
                        if(node->left)
                                s1.push(node->left);
                }
                if(temp.size()>0)
                {
                ans.push_back(temp);
                temp.clear();
                }
        }
            
        return ans;
            
    }
};