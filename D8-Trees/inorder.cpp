/*Inorder Traversal*/
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

/*Recursive*/
class Solution {
    void inorder(TreeNode* root,vector<int>& ans)
    {
           if(root->left!=NULL)
           {
                   inorder(root->left,ans);
           }
            
           ans.push_back(root->val);
           
           if(root->right!=NULL)
           {
                   inorder(root->right,ans);
           }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
            if(!root)
            {
                    vector<int> t;
                    return t ;
            }
            vector<int> ans;
            inorder(root,ans);
            return ans;
        
    }
};



/*Iterative */

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
    vector<int> inorderTraversal(TreeNode* root) {
            TreeNode *curr = root;
            stack<TreeNode *> s1;
            vector<int> ans;
            while(curr!=NULL || !s1.empty())
            {
                    while(curr!=NULL)
                    {
                            s1.push(curr);
                            curr = curr->left;
                    }
                    
                    curr = s1.top();
                    s1.pop();
                    ans.push_back(curr->val);
                    curr = curr->right;
                    
                    
            }
            
            
            return ans;
            
        
    }
};


/*
Approach:
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/