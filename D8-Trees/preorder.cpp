/*Preorder Traversal*/
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
/*using recursion*/
class Solution {
    void preorder(TreeNode* root,vector<int>& ans)
    {
            ans.push_back(root->val);
            if(root->left)
            {
                    preorder(root->left,ans);
            }
            
            if(root->right)
            {
                    preorder(root->right,ans);
            }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(!root)
                    return ans;
            preorder(root,ans);
            return ans;
        
    }
};

//Using iteration
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
    vector<int> preorderTraversal(TreeNode* root) {
            TreeNode *curr = root;
            stack<TreeNode *> s1;
            vector<int> ans;
            while(curr!=NULL || !s1.empty())
            {
                    while(curr)
                    {
                            ans.push_back(curr->val);
                            s1.push(curr);
                            curr = curr->left;
                    }
                    
                    curr = s1.top();
                    s1.pop();
                    curr = curr->right;
            }
            
            return ans;
        
    }
};